import textwrap

def wrap(string, max_width):
    lines = textwrap.wrap(string, max_width)
    print("\n").join(lines)

wrap("ABCDEFGHIJKLIMNOQRSTUVWXYZ", 4)
