%{
    #include <stdio.h>
    int int_count = 0;
    int char_count = 0;
    int return_count = 0;
    int if_count = 0;
    int else_count = 0;
    int while_count = 0;
    int for_count = 0;
    int switch_count = 0;
    int case_count = 0;
    int default_count = 0;
    int void_count = 0;
    int typedef_count = 0;
    int struct_count = 0;
    int union_count = 0;
    int enum_count = 0;
    int long_count = 0;
    int short_count = 0;
    int double_count = 0;
    int float_count = 0;
    int const_count = 0;
    int unsigned_count = 0;
    int signed_count = 0;
    int volatile_count = 0;
    int goto_count = 0;
    int sizeof_count = 0;
    int break_count = 0;
    int continue_count = 0;
    int static_count = 0;
    int inline_count = 0;
%}

%%
"int" {int_count++;}
"char" {char_count++;}
"return" {return_count++;}
"if" {if_count++;}
"else" {else_count++;}
"while" {while_count++;}
"for" {for_count++;}
"switch" {switch_count++;}
"case" {case_count++;}
"default" {default_count++;}
"void" {void_count++;}
"typedef" {typedef_count++;}
"struct" {struct_count++;}
"union" {union_count++;}
"enum" {enum_count++;}
"long" {long_count++;}
"short" {short_count++;}
"double" {double_count++;}
"float" {float_count++;}
"const" {const_count++;}
"unsigned" {unsigned_count++;}
"signed" {signed_count++;}
"volatile" {volatile_count++;}
"goto" {goto_count++;}
"sizeof" {sizeof_count++;}
"break" {break_count++;}
"continue" {continue_count++;}
"static" {static_count++;}
"inline" {inline_count++;}
"0" {return 0;}
%%

int main() {
    printf("Enter a string to count keywords (type '0' to exit): ");
    yylex();
    
    printf("int count: %d\n", int_count);
    printf("char count: %d\n", char_count);
    printf("return count: %d\n", return_count);
    printf("if count: %d\n", if_count);
    printf("else count: %d\n", else_count);
    printf("while count: %d\n", while_count);
    printf("for count: %d\n", for_count);
    printf("switch count: %d\n", switch_count);
    printf("case count: %d\n", case_count);
    printf("default count: %d\n", default_count);
    printf("void count: %d\n", void_count);
    printf("typedef count: %d\n", typedef_count);
    printf("struct count: %d\n", struct_count);
    printf("union count: %d\n", union_count);
    printf("enum count: %d\n", enum_count);
    printf("long count: %d\n", long_count);
    printf("short count: %d\n", short_count);
    printf("double count: %d\n", double_count);
    printf("float count: %d\n", float_count);
    printf("const count: %d\n", const_count);
    printf("unsigned count: %d\n", unsigned_count);
    printf("signed count: %d\n", signed_count);
    printf("volatile count: %d\n", volatile_count);
    printf("goto count: %d\n", goto_count);
    printf("sizeof count: %d\n", sizeof_count);
    printf("break count: %d\n", break_count);
    printf("continue count: %d\n", continue_count);
    printf("static count: %d\n", static_count);
    printf("inline count: %d\n", inline_count);

    exit(0);

    return 0;
}

int yywrap() {
    return 1;
}
