import sys

def solve():
    t = int(sys.stdin.readline())
    for _ in range(t):
        k, C = map(int, sys.stdin.readline().split())
        a = list(map(int, sys.stdin.readline().split()))
        
        current = list(range(1, C + 1))
        changed = True
        while changed:
            changed = False
            to_remove_indices = set()
            max_pos = len(current)
            for num in a:
                pos = num - 1  
                if pos < max_pos:
                    to_remove_indices.add(pos)
            if to_remove_indices:
                changed = True
                sorted_indices = sorted(to_remove_indices, reverse=True)
                for idx in sorted_indices:
                    if idx < len(current):
                        del current[idx]
        print(len(current))

solve()