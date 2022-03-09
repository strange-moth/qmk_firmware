#!/bin/python3

import fileinput
import regex as re

trans_dict = {
        "space" : " ",
        "question" : "?",
        "slash" : "/",
        "period" : ".",
        "greater" : ">",
        "less" : "<",
        "comma" : ",",
        "apostrophe" : "'",
        "quotedbl" : '\\"',
        "semicolon" : ";",
        "colon" : ":",
        "backslash" : "\\\\",
        "bar" : "|",
        "bracketright" : "]",
        "braceright" : "}",
        "bracketleft" : "[",
        "braceleft" : "{",
        "exclam" : "!",
        "at" : "@",
        "numbersign" : "#",
        "dollar" :  "$",
        "percent" : "%",
        "asciicircum" : "^",
        "ampersand" : "&",
        "asterisk" : "*",
        "parenleft" : "(",
        "parenright" : ")",
        "minus" : "-",
        "underscore" : "_",
        "equal" : "=",
        "plus" : "+"
        }

def trans(s):
    if (len(s)==1):
        return s
    if (s in trans_dict):
        return trans_dict[s]
    return None

outlines = []
for line in fileinput.input():
    if (line.startswith("#")):
        continue
    keys, output = line.split(":", 1)
    keys = re.findall(r"<([^>]+)>",keys)
    output = re.findall("^\s+\"([^\"]+)\"", output)[0]
    if (keys[0] != "Multi_key"):
        continue
    keys = keys[1:]
    keys = [trans(x) for x in keys]
    if (None in keys):
        continue
    output = ",".join((hex(ord(x)) for x in output))
    outlines.append('UCIS_SYM("'+"".join(keys)+'",'+output+')')

print("const qk_ucis_symbol_t ucis_symbol_table[] = UCIS_TABLE(")
for l in outlines[:-1]:
    print(l+",")
print(outlines[-1])
print(");")

