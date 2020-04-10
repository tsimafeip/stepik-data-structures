import sys

def height_func(tree, cur_index):
    height = 0
    for child in tree.get(cur_index, []):
        height = max(height, 1+height_func(tree, child))
    return height


def build_tree(string):
    tree = {}
    [tree.setdefault(int(parent), []).append(index) for index, parent in enumerate(string.split())]
    return height_func(tree, -1)


if __name__ == '__main__':
    sys.setrecursionlimit(20000)
    n = input()
    print(build_tree(input()))
