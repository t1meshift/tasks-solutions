#include <stdio.h>
#include <stdbool.h>

#define TEST_STR "It's a test, 1/0 == inf /**/ //hello"

#define ARR_SIZE(x) (sizeof(x)/sizeof(x[0]))

int main(int argc, char** argv) {
	  // K&R C 2nd edition task #1-23
	  // Has been tested on its own source code
    
    // Single comment test
    /*
     * Multiline
     * comment
     * test
     */
    FILE *inp;
    FILE *outp;
    inp = fopen("input.c", "r");
    outp = fopen("output.c", "w");
    int symbol;
    long long pos;

    bool single_quote = false;
    bool double_quote = false;

    while ((symbol = fgetc(inp)) != EOF) {
        switch (symbol) {
            case '"':
                if (!single_quote)
                    double_quote = !double_quote;
                fputc(symbol, outp);
                break;
            case '\'':
                if (!double_quote)
                    single_quote = !single_quote;
                fputc(symbol, outp);
                break;
            case '/':
                fgetpos(inp, &pos);
                printf("%d %d at pos %lld\n", single_quote, double_quote, pos);
                if (!(single_quote || double_quote)) {
                    symbol = fgetc(inp);
                    if (symbol == '/') {
                        while (fgetc(inp) != '\n');
                    }
                    else if (symbol == '*') {
                        while ((symbol = fgetc(inp)) != EOF) {
                            if (symbol == '*') {
                                if (fgetc(inp) == '/') {
                                    break;
                                }
                            }
                        }
                    }
                    else {
                        fputc('/', outp);
                        fputc(symbol, outp);
                    }
                }
                else {
                    fputc(symbol, outp);
                }
                break;
            default:
                fputc(symbol, outp);
                break;
        }
    }
    fclose(inp);
    fclose(outp);
    return 0;
}
