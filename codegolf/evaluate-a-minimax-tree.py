"""

Alice and Bob are playing a little game. First, they draw a tree from a root node (indicated by a thick dot), with no internal nodes, with numbers at the leaves. Any node may have any number of children.

We start at the root, and first to play is Alice (A). She must select one of the current node's children. Then it's Bob's turn, and he similarly selects a child node. This continues until a leaf node is reached.

When a leaf node is reached, the game is over. It is Alice's goal to end at a node with as large of a value as possible, and Bob's goal to end at a node with as small of a value as possible.

Given a tree in nested array form, return the value of the leaf that will be reached if both Alice and Bob play perfectly.

Examples:

18: [[67, [[100, [[67, 47], [86], 21, 16], [[46, [14], 35, 85], [71, [18, 63, 69], 99, 22], 3]]], [[18, 32, 42, 80]], [[36, 70], [86, 53, 46, 59], [[41], 86, 35]]], 3]
60: [[[84, 35], [44, 60]], [[24, 98], [16, 21]]]
58: [[53, 77], [58, [82, 41]], 52]
59: [[93, [100, 53], 58, 79], [63, 94, 59], [9, [55, 48]], [40, 10, 32]]
56: [[20, 10, [[[89, 22, 77, 10], 55], [24, 28, 30, 63]]], [[49, 31]], 17, 56]
0: [0]

You may assume that the root node never is a leaf node and points to at least one leaf node. You may assume that leafs are nonnegative numbers.

Shortest code in bytes wins.

"""

def minimax(t, d=0):
    if isinstance(t, list):
        i = 0
        m = 0
        for n in t:
            v = minimax(n, d+1)
            if i == 0:
                m = v
            elif d%2 == 0:
                m = max(m, v)
            else:
                m = min(m, v)
            i += 1
        return m
    
    return t

def main():
    t1 = [[67, [[100, [[67, 47], [86], 21, 16], [[46, [14], 35, 85], [71, [18, 63, 69], 99, 22], 3]]], [[18, 32, 42, 80]], [[36, 70], [86, 53, 46, 59], [[41], 86, 35]]], 3]
    t2 = [[[84, 35], [44, 60]], [[24, 98], [16, 21]]]
    t3 = [[53, 77], [58, [82, 41]], 52]
    t4 = [[93, [100, 53], 58, 79], [63, 94, 59], [9, [55, 48]], [40, 10, 32]]
    t5 = [[20, 10, [[[89, 22, 77, 10], 55], [24, 28, 30, 63]]], [[49, 31]], 17, 56]
    t6 = [0]

    assert(minimax(t1) == 18)
    assert(minimax(t2) == 60)
    assert(minimax(t3) == 58)
    assert(minimax(t4) == 59)
    assert(minimax(t5) == 56)
    assert(minimax(t6) == 0)

main()
