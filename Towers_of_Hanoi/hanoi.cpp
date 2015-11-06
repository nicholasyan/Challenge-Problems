#include <iostream>
#include <stack>

using std::cout;
using std::stack;

struct tower {
    stack<int> disks;
    int        tower_num;
};

void solve_towers(int n);
void initialize_towers(tower htowers[], int n);
void move_disk(int disk_num, tower &source, tower &dest, tower &temp);
void move_top_disk(tower &source, tower &dest);

int main(int argc, char **argv)
{
    if (argc != 2) {
        cout << "usage: ./hanoi [num_plates]\n";
        exit(1);
    }

    int n = atoi(argv[1]);
  
    solve_towers(n);

    return 0; 
}

void solve_towers(int n)
{ 
    tower htowers[3];
    initialize_towers(htowers, n);
   
    move_disk(htowers[0].disks.size(), htowers[0], htowers[2], htowers[1]);

}

void initialize_towers(tower htowers[], int n)
{
    htowers[0].tower_num = 1;
    htowers[1].tower_num = 2;
    htowers[2].tower_num = 3;

    for (int i = n; i > 0; i--) {
        htowers[0].disks.push(i);
    }
}

void move_disk(int disk_num, tower &source, tower &dest, tower &temp)
{
    if (disk_num == 1) {

        move_top_disk(source, dest);
        
    } else {

        move_disk(disk_num - 1, source, temp, dest); 
        move_top_disk(source, dest);
        move_disk(disk_num - 1, temp, dest, source);
         
    }

}

void move_top_disk(tower &source, tower &dest)
{
    int disk = source.disks.top();
    source.disks.pop();
    dest.disks.push(disk);

    cout << "move disk " << disk << " from rod " << source.tower_num << " " \
         << "to rod " << dest.tower_num << "\n";

    return;
}
