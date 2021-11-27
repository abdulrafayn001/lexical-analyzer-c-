# Lexical Analyzer c++

## Features

- Read the source code
- Generate tokens
- Identify Lexical Errors

## Language
|  | Detail |
| ------ | ------ |
| Identifiers | Start from _ or Letter and contains at least one “_”. Other rules for ID will remain same. |
| Numbers |[ + \| - ] ? (D+) (\.D+)?,  and exponent numbers. |
| Operators | !=, <>, =:= , ==, *, +, /,-, >>,<<, ++, =+, &&, \|\|, =>, =<, %, :, :: , --  |
| Punctuation |  [,{,< , >,},] |
| Keyword | loop, agar, magar,  asm,  else, new, this, auto, enum, operator, throw, bool , explicit, private, true, break, export, protected , try,  case, extern, public, typedef, catch,  false, register, typeid, char, float, typename, class,  for, return, union, const,  friend, short, unsigned, goto,  signed,  using, continue, if, sizeof, virtual, default, inline,  static, void, delete, int, volatile, do, long, struct, double,  mutable,  switch,  while,  namespace |
