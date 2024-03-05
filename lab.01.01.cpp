#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Call {
    char *from_number;
    char *to_number;
    char *date;
    char *from_time;
    char *end_time;
};

struct Node {
    struct Call data;
    struct Node *next;
};

int is_valid_phone_number(const char *number) {
    for (int i = 0; i < 10; ++i) {
        if (number[i] < '0' || number[i] > '9') {
            return 0;
        }
    }
    return 1;
}

void free_calls(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp->data.from_number);
        free(temp->data.to_number);
        free(temp->data.date);
        free(temp->data.from_time);
        free(temp->data.end_time);
        free(temp);
    }
}

int main() {
    struct Node *head = NULL;
    struct Node *tail = NULL;

    // Đọc dữ liệu cuộc gọi
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (buffer[0] == '#') {
            break;
        }

        struct Call call;
        call.from_number = malloc(11 * sizeof(char));
        call.to_number = malloc(11 * sizeof(char));
        call.date = malloc(11 * sizeof(char));
        call.from_time = malloc(9 * sizeof(char));
        call.end_time = malloc(9 * sizeof(char));

        sscanf(buffer, "call %s %s %s %s %s",
               call.from_number,
               call.to_number,
               call.date,
               call.from_time,
               call.end_time);

        if (!is_valid_phone_number(call.from_number) ||
            !is_valid_phone_number(call.to_number)) {
            fprintf(stderr, "Invalid phone number detected.\n");
            free(call.from_number);
            free(call.to_number);
            free(call.date);
            free(call.from_time);
            free(call.end_time);
            free_calls(head); // Giải phóng bộ nhớ đã cấp phát trước khi thoát
            return 1;
        }

        struct Node *new_node = malloc(sizeof(struct Node));
        new_node->data = call;
        new_node->next = NULL;

        if (head == NULL) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
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
                struct Node *current = head;
                while (current != NULL) {
                    if (!is_valid_phone_number(current->data.from_number) ||
                        !is_valid_phone_number(current->data.to_number)) {
                        is_valid = 0;
                        break;
                    }
                    current = current->next;
                }
                printf("%d\n", is_valid);
            } else if (strcmp(query_type, "?number_calls_from") == 0) {
                int count = 0;
                struct Node *current = head;
                while (current != NULL) {
                    if (strcmp(current->data.from_number, phone_number) == 0) {
                        count++;
                    }
                    current = current->next;
                }
                printf("%d\n", count);
            } else if (strcmp(query_type, "?number_total_calls") == 0) {
                int count = 0;
                struct Node *current = head;
                while (current != NULL) {
                    count++;
                    current = current->next;
                }
                printf("%d\n", count);
            } else if (strcmp(query_type, "?count_time_calls_from") == 0) {
                struct Node *current = head;
                while (current != NULL) {
                    if (strcmp(current->data.from_number, phone_number) == 0) {
                        int from_hour, from_min, from_sec, end_hour, end_min, end_sec;
                        sscanf(current->data.from_time, "%d:%d:%d", &from_hour, &from_min, &from_sec);
                        sscanf(current->data.end_time, "%d:%d:%d", &end_hour, &end_min, &end_sec);
                        total_time += (end_hour - from_hour) * 3600 + (end_min - from_min) * 60 + (end_sec - from_sec);
                    }
                    current = current->next;
                }
                printf("%d\n", total_time);
            } else {
                fprintf(stderr, "Invalid query type.\n");
                free_calls(head); // Giải phóng bộ nhớ đã cấp phát trước khi thoát
                return 1;
            }
        }
    }

    free_calls(head); // Giải phóng bộ nhớ trước khi kết thúc chương trình
    return 0;
}
