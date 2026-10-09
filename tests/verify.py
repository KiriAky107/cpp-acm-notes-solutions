from pathlib import Path
import concurrent.futures, subprocess, shutil, json, argparse, re, collections, time

ROOT=Path(__file__).resolve().parents[1]
parser=argparse.ArgumentParser();parser.add_argument('--compiler',default=shutil.which('g++'));parser.add_argument('--jobs',type=int,default=4)
args=parser.parse_args()
if not args.compiler:raise SystemExit('请在 PATH 中配置 g++，或用 --compiler 指定编译器路径。')
BUILD=ROOT/'build';BUILD.mkdir(exist_ok=True)
MANIFEST=json.loads((ROOT/'manifest.json').read_text(encoding='utf-8'))

def hanoi_state(text):
    lines=text.splitlines();n=int(lines[0]);state=[0]*n;target=[0]*n
    for peg in range(3):
        for disk in map(int,lines[1+peg].split()[1:]):state[disk-1]=peg
        for disk in map(int,lines[4+peg].split()[1:]):target[disk-1]=peg
    return tuple(state),tuple(target)

def hanoi_neighbors(state):
    top=[None]*3
    for disk,peg in enumerate(state):
        if top[peg] is None:top[peg]=disk
    for source in range(3):
        disk=top[source]
        if disk is None:continue
        for dest in range(3):
            if dest!=source and (top[dest] is None or top[dest]>disk):
                nxt=list(state);nxt[disk]=dest;yield tuple(nxt)

def hanoi_shortest(start,target):
    q=collections.deque([start]);dist={start:0}
    while q:
        s=q.popleft()
        if s==target:return dist[s]
        for t in hanoi_neighbors(s):
            if t not in dist:dist[t]=dist[s]+1;q.append(t)

def validate(pid,stdin,stdout,expected):
    if pid=='B3644':
        lines=stdin.splitlines();n=int(lines[0]);order=list(map(int,stdout.split()))
        if sorted(order)!=list(range(1,n+1)):return False
        rank={v:i for i,v in enumerate(order)}
        return all(rank[u]<rank[v] for u in range(1,n+1) for v in map(int,lines[u].split()) if v)
    if pid=='P1242':
        state,target=hanoi_state(stdin);lines=stdout.strip().splitlines()
        if not lines:return False
        count=int(lines[-1])
        if count!=len(lines)-1:return False
        for line in lines[:-1]:
            match=re.fullmatch(r'move (\d+) from ([ABC]) to ([ABC])',line)
            if not match:return False
            disk=int(match[1])-1;source=ord(match[2])-65;dest=ord(match[3])-65
            if state[disk]!=source or source==dest:return False
            if any(state[i] in [source,dest] for i in range(disk)):return False
            nxt=list(state);nxt[disk]=dest;state=tuple(nxt)
        start,_=hanoi_state(stdin)
        return state==target and count==hanoi_shortest(start,target)
    if pid=='P3382':
        actual=float(stdout);reference=float(expected)
        if abs(actual-reference)<=1e-5*max(1,abs(reference)):return True
        tokens=stdin.split();coefs=list(map(float,tokens[3:]));
        def poly(x):
            y=0
            for a in coefs:y=y*x+a
            return y
        return abs(poly(actual)-poly(reference))<=1e-5*max(1,abs(poly(reference)))
    return stdout.split()==expected.split()

def verify(item):
    pid=item['id'];exe=BUILD/(pid+('.exe' if __import__('os').name=='nt' else ''))
    start=time.monotonic()
    result=subprocess.run([args.compiler,'-std=gnu++17','-O2','-Wall','-Wextra',str(ROOT/item['cpp']),'-o',str(exe)],capture_output=True,text=True,encoding='utf-8',errors='replace')
    if result.returncode:return {'id':pid,'success':False,'phase':'compile','error':result.stderr[-5000:]}
    count=0
    for test in item['tests']:
        run=subprocess.run([str(exe)],input=test['input'],capture_output=True,text=True,encoding='utf-8',errors='replace',timeout=15)
        if run.returncode or not validate(pid,test['input'],run.stdout,test['output']):
            return {'id':pid,'success':False,'phase':'run','input':test['input'],'expected':test['output'],'actual':run.stdout,'returncode':run.returncode}
        count+=1
    return {'id':pid,'success':True,'tests':count,'seconds':round(time.monotonic()-start,2)}

if __name__=='__main__':
    with concurrent.futures.ThreadPoolExecutor(max_workers=args.jobs) as pool:results=list(pool.map(verify,MANIFEST))
    (BUILD/'verification.json').write_text(json.dumps(results,ensure_ascii=False,indent=2),encoding='utf-8')
    failed=[x for x in results if not x['success']]
    print(json.dumps({'programs':len(results),'passed':len(results)-len(failed),'cases':sum(x.get('tests',0) for x in results),'failures':failed},ensure_ascii=False))
    raise SystemExit(bool(failed))
