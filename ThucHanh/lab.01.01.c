#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CALLS 100000

struct Call {
    string from_number;
    string to_number;
    char date;
    char from_time;
    char end_time[9];
};

int is_valid_phone_number(const char *number) {
    for (int i = 0; i < 10; ++i) {
        if (number[i] < '0' || number[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int main() {
    struct Call calls[MAX_CALLS];
    int num_calls = 0;

    // Đọc dữ liệu cuộc gọi
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (buffer[0] == '#') {
            break;
        }

        sscanf(buffer, "call %s %s %s %s %s",
               calls[num_calls].from_number,
               calls[num_calls].to_number,
               calls[num_calls].date,
               calls[num_calls].from_time,
               calls[num_calls].end_time);

        if (!is_valid_phone_number(calls[num_calls].from_number) ||
            !is_valid_phone_number(calls[num_calls].to_number)) {
            fprintf(stderr, "Invalid phone number detected.\n");
            return 1;
        }

        num_calls++;
    }

    // Thực hiện các truy vấn
    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (buffer[0] == '#') {
            break;
        }

        if (buffer[0] == '?') {
            char query_type[20];
            char phone_number[11];
            int total_time = 0;
            sscanf(buffer, "%s %s", query_type, phone_number);

            if (strcmp(query_type, "?check_phone_number") == 0) {
                int is_valid = 1;
                for (int i = 0; i < num_calls; i++) {
                    if (!is_valid_phone_number(calls[i].from_number) ||
                        !is_valid_phone_number(calls[i].to_number)) {
                        is_valid = 0;
                        break;
                    }
                }
                printf("%d\n", is_valid);
            } else if (strcmp(query_type, "?number_calls_from") == 0) {
                int count = 0;
                for (int i = 0; i < num_calls; i++) {
                    if (strcmp(calls[i].from_number, phone_number) == 0) {
                        count++;
                    }
                }
                printf("%d\n", count);
            } else if (strcmp(query_type, "?number_total_calls") == 0) {
                printf("%d\n", num_calls);
            } else if (strcmp(query_type, "?count_time_calls_from") == 0) {
                for (int i = 0; i < num_calls; i++) {
                    if (strcmp(calls[i].from_number, phone_number) == 0) {
                        int from_hour, from_min, from_sec, end_hour, end_min, end_sec;
                        sscanf(calls[i].from_time, "%d:%d:%d", &from_hour, &from_min, &from_sec);
                        sscanf(calls[i].end_time, "%d:%d:%d", &end_hour, &end_min, &end_sec);
                        total_time += (end_hour - from_hour) * 3600 + (end_min - from_min) * 60 + (end_sec - from_sec);
                    }
                }
                printf("%d\n", total_time);
            } else {
                fprintf(stderr, "Invalid query type.\n");
                return 1;
            }
        }
    }

    return 0;
}
