# Numbered-List-Generator
This is a small C application for windows (if anyone knows how to implement on linux feel free to make a pr) which can generate numbered lists

The format string (```FSTRING```) takes a string with ```?``` as the replacer. There is also a ```START``` (optional: default=0), ```END```, and ```STEP``` (optional: default=1) parameter. You can use ```\``` as an escape character.

```
USAGE: generator [FSTRING] [optional: START] [END] [optional: STEP]
```
