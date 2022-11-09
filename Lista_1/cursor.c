#include <stdio.h>

int find_last_digit(char *text);

int main(){
    int num_lines;
    int line_i;
    int column_i;
    int next_line;
    int next_column;
    int helperF;

    char command;
    char text[1000][1000];

    scanf("%d", &num_lines);

    for (int i = 1; i <= num_lines; i++){
        scanf(" %1000[^\n]s", text[i]);
    }

    scanf("%d %d", &line_i, &column_i);
    next_line = line_i;
    next_column = column_i;

    while (scanf("\n%c", &command) != EOF){

        if (command == 'j'){
            if ((next_line + 1) <= num_lines){
                next_line = next_line + 1;

                helperF = find_last_digit(text[next_line]);

                if ((next_column > helperF) || (next_column < helperF && helperF < column_i)){
                    next_column = helperF;
                }
                else{
                    next_column = column_i;
                }
            }
        }

        if (command == 'k'){

            if (next_line > 1){
                next_line = next_line - 1;

                helperF = find_last_digit(text[next_line]);

                if (next_column > helperF || (next_column < helperF && helperF < column_i))
                {
                    next_column = helperF;
                }
                else
                {
                    next_column = column_i;
                }
            }
        }
        printf("%d %d %c\n", next_line, next_column, text[next_line][next_column - 1]);
    }

    return 0;
}

int find_last_digit(char *matrix){
    int contador = 0;

    for (int j = 0; j < 1004; j++){
        if (matrix[j] != '\0'){
            contador++;
        }
        else{
            return contador;
        }
    }
}