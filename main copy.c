#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    system("clear");
    
    time_t a = 0;
    
    while (1) {
        struct tm *data_hora_atual;
        time_t segundos;
        
        time(&segundos);
        
        if (segundos != a) {
            a = segundos;
            
            data_hora_atual = localtime(&segundos);
            printf("\033[H\033[J"); // Limpa a tela e reposiciona o cursor
            
            printf("\nDia..........: %d\n", data_hora_atual->tm_mday);
            printf("Mes..........: %d\n", data_hora_atual->tm_mon + 1);
            printf("Ano..........: %d\n\n", data_hora_atual->tm_year + 1900);
            
            printf("Dia do ano...: %d\n", data_hora_atual->tm_yday);
            printf("Dia da semana: %d\n\n", data_hora_atual->tm_wday);
            
            printf("Hora ........: %d:", data_hora_atual->tm_hour);
            printf("%d:", data_hora_atual->tm_min);
            printf("%d\n", data_hora_atual->tm_sec);
            
            printf("Data ........: %d/", data_hora_atual->tm_mday);
            printf("%d/", data_hora_atual->tm_mon + 1);
            printf("%d\n\n", data_hora_atual->tm_year + 1900);
            
           
        }
    }
    
    return 0;
}
