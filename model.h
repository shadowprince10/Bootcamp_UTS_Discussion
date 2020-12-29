struct character
{
    char name[255];
    char job[255];
    int level;
    int damage;
};

struct node
{
    character c;
    node *left, *right;
};

struct student
{
    char name[255];
    char NIM[255];
};

struct stack
{
    student s;
    node *left, *right;
};