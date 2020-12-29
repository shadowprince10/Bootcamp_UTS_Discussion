#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../controller/controller.h"

int main()
{
    bool game = true;
    node *base_root = NULL;
    int input;

    while (game)
    {
        puts("BLUE-LUNA ONLINE");
        puts("----------------");
        puts("1. View All Characters");
        puts("2. Add New Character");
        puts("3. Inorder, Preorder, Postorder Characters' Damage");
        puts("4. Exit and Pop All");

        do
        {
            scanf("%d", &input);
        } while (input < 1 || input > 4);

        // break;
        game = false; // menangkap user di main menu
    }

    switch(input)
    {
        case 1: // menu pertama
            if(!base_root)
            {
                puts("--- There's no character in the tree ---");
            }

            else
            {
                print_all(base_root);
            }
            

        case 2:
            character dummy;
            bool is_name_valid, is_job_valid, is_level_valid;

            is_name_valid = true;

            do
            {
                is_name_valid = true;
                printf("Input Character's Name [3..20][non space char]: ");
                // scanf("%[^\n], dummy.name"); getchar();
                scanf("%s", dummy.name);
                int len = strlen(dummy.name);

                for (int i = 0; i < len; i++)
                {
                    if (dummy.name[i] == ' ')
                    {
                        is_name_valid = false;
                    }
                }

                if (len < 3 || len > 20)
                {
                    is_name_valid = false;
                }
            } while (!is_name_valid); // atau sama dengan is_name_valid = false


            is_job_valid = false;
            do
            {
                is_job_valid = false;
                printf("Input Character's Job [fighter/rogue/mage]: ");
                scanf("%s", dummy.job);

                if (strcmp(dummy.job, "fighter") == 0 || strcmp(dummy.job, "rogue") == 0 || strcmp(dummy.job, "mage") == 0)
                {
                    is_job_valid = true;
                }
            } while (!is_job_valid); // kalau is_job_valid true
            

            is_level_valid = true;
            do
            {
                is_level_valid = true;
                printf("Input Character's Level [1..105]: ");
                scanf("%d", dummy.level);

                if (dummy.level < 1 || dummy.level > 105)
                {
                    is_level_valid = false;
                }
            } while (!is_level_valid);

            // system(@cls || @clear); // buat jalan di dua operating system
            system("cls");

            srand(time(NULL)); // srand itu void dan tidak return apa-apa
            // int random_number = -1; // validasi = -1 jika untuk alasan apapun tiba-tiba rand aku broken dna dia gak timpa random-nya. Nanti akan masuk -1, nanti bisa dilihat kalau dummy level 50
            // Kalau dia berhasil lolos dari tiga buah if ini, nanti di testcase, kalau misalnya ada kasus dummy level -1, berarti fungsi rand broken
            // kalau ada rand dan fungsi tambahan, harus expect kalau bisa saja ada sesuatu negatif yang terjadi

            // hasil dari rand() hanya bisa menimpa sebuah NULL value, jadi tidak perlu sama dengan -1
            int random_number;

            if (strcmp(dummy.job, "fighter") == 0)
            {
                random_number = rand() % 50; // 0 - 49
            }

            else if (strcmp(dummy.job, "rogue") == 0)
            {
                // arc4random yang baru untuk akurasi random yang benar. BINUS masih pakai rand
                random_number = rand() % 25; // 0 - 24
            }

            else
            {
                random_number = rand() % 75; // 0 - 74
            }

            dummy.damage = dummy.level + random_number;
            base_root = insert_node(base_root, dummy);
            puts("--- Add New Character Successful! ---");
            break;

        case 3: 
            print_damage(base_root);
            break;

        case 4:
            game = false;
            pop_all(base_root);
            break;    
    }

    return 0;
}