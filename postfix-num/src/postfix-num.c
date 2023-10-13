/*
 * > Postfix Numbers (postfix-num.c)
 * A REPL that parses numerical expressions and transforms them into
 * their postfix form.
 * By: anachan01h
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include <stdio.h>
#include <string.h>

static int lookahead;
static int counter;

int main() {
    int expr(char *expr_in, char *expr_out);
    char expr_in[50], expr_out[50];

    while(1) {
        printf("> ");
        fgets(expr_in, 50, stdin);
        counter = 0;
        lookahead = 0;
        if (expr(expr_in, expr_out) < 0)
            printf("Syntax error! :(\n");
        else
            printf("%s\n", expr_out);
    }
    return 0;
}

int expr(char *expr_in, char *expr_out) {
    int term(char *expr_in, char *expr_out);
    void match(char *expr_in, char t);

    int err = term(expr_in, expr_out);
    if (err < 0)
        return err;
    
    while(1) {
        switch(expr_in[lookahead]) {
            case '+':
                match(expr_in, '+');
                err = term(expr_in, expr_out);
                if (err < 0)
                    return err;
                expr_out[counter++] = '+';
                //printf("+");
                continue;
            case '-':
                match(expr_in, '-');
                err = term(expr_in, expr_out);
                if (err < 0)
                    return err;
                expr_out[counter++] = '-';
                //printf("-");
                continue;
        }
        break;
    }

    expr_out[counter] = 0;

    if (strlen(expr_out) == strlen(expr_in) - 1)
        return 0;
    else
        return -1;
}

int term(char *expr_in, char *expr_out) {
    void match(char *expr_in, char t);
    if (expr_in[lookahead] < 58 && expr_in[lookahead] >= 48) {
        expr_out[counter++] = expr_in[lookahead];
        //printf("%c", expr_in[lookahead]);
        match(expr_in, expr_in[lookahead]);
    } else {
        return -1;
    }
    return 0;
}

void match(char *expr_in, char t) {
    if (expr_in[lookahead] == t)
        lookahead += 1;
    else if (expr_in[lookahead] == 0)
        return;
    else
        printf("Syntax error in 'match'! :(");
}
