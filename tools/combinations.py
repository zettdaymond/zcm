import itertools
import sys

if len(sys.argv) < 3:
    print(f'Usage: {sys.argv[0]} <vector size> <permutation length>')
    sys.exit(1)

comps = int(sys.argv[1])
count = int(sys.argv[2])

assert comps >= count

product = list(itertools.product(range(comps), repeat=count))

for permutation in product:
    rev_p =list(reversed(permutation))
    indices = ", ".join(str(index) for index in rev_p)
    letters_xyzw = "".join("xyzw"[index] for index in rev_p)
    letters_rgba = "".join("rgba"[index] for index in rev_p)
    letters_stpq = "".join("stpq"[index] for index in rev_p)

    print(f'detail::shuffle_accessor_{comps}<vec{count}, {indices}> {letters_xyzw}, {letters_rgba}, {letters_stpq};')
