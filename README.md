# Numbered-List-Generator
This is a small C application for windows (if anyone knows how to implement on linux feel free to make a pr) which can generate numbered lists

The format string (```FSTRING```) takes a string with ```?``` as the replacer. There is also a ```START``` (optional: default=0), ```END```, and ```STEP``` (optional: default=1) parameter. You can use ```\``` as an escape character.

USAGE:
```
generator [FSTRING] [optional: START] [END] [optional: STEP]
```
EXAMPLE:
```bash
$ ./generator.exe "?. This is an item. Specifically item ?. This has a \? for some reason." 5
0. This is an item. Specifically item 0. This has a ? for some reason.
1. This is an item. Specifically item 1. This has a ? for some reason.
2. This is an item. Specifically item 2. This has a ? for some reason.
3. This is an item. Specifically item 3. This has a ? for some reason.
4. This is an item. Specifically item 4. This has a ? for some reason.
```
