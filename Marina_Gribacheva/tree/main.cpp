#include <iostream>
#include <fstream>
#define N 26

using namespace std;

struct broom{
    char let;
    int num;
    broom* next[N];
};

void add_node(broom* node, int u, int v, char c);
//void delete_node(broom* node, int num);
void get_height(broom* node, int* h, int cnt);
void get_node_cnt(broom* node, int* ncnt);
void null_node(broom* node);

int main(){
    setlocale(0, "rus");
    ifstream fin("input.txt");
    int n, u, v;
    char c;
    int* h = new int;
    int* ncnt = new int;
    *h = 0;
    *ncnt = 1;
    broom* root = new broom;
    root->num = 1;
    null_node(root);
    fin >> n;
    while (!fin.eof()){
        fin >> u >> v >> c;
        add_node(root, u, v, c);
    }
    get_height(root, h, 0);
    get_node_cnt(root, ncnt);
    cout << "Высота дерева: " << *h << endl;
    cout << "Кол-во узлов в дереве: " << *ncnt << endl;
    fin.close();
}

void add_node(broom* node, int u, int v, char c){
    if (u == 1){
        //int k = c-'a';
        node->next[c-'a'] = new broom;
        //broom* cur = node->next[c-'a'];
        node->next[c-'a']->num = v;
        node->next[c-'a']->let = c;
        null_node(node->next[c-'a']);
    }
    else{
        for (int i=0; i<N; i++){
            if (node->next[i] != NULL){
                if (node->next[i]->num == u){
                    node->next[i]->next[c-'a'] = new broom;
                    broom* cur;
                    cur = node->next[i]->next[c-'a'];
                    cur->let = c;
                    cur->num = v;
                    null_node(cur);
                }
                else{
                    add_node(node->next[i], u, v, c);
                }
            }
        }
    }
}

void null_node(broom* node){
    for (int i=0; i<N; i++){
        node->next[i] = NULL;
    }
}

void get_height(broom* node, int* h, int cnt){
    for (int i=0; i<N; i++){
        if (node->next[i] != NULL){
            get_height(node->next[i], h, cnt+1);
        }
        else{
            if (cnt > *h){
                *h = cnt;
            }
        }
    }
}

void get_node_cnt(broom* node, int* ncnt){
    for (int i=0; i<N; i++){
        if (node->next[i] != NULL){
            *ncnt = *ncnt + 1;
            get_node_cnt(node->next[i], ncnt);
        }
    }
}

/*void delete_node(broom* node, int num){
    for (int i=0; i<N; i++){
        if (node->next[i] != NULL){
            if (node->next[i]->num != num){
                delete_node(node->next[i], num);
            }
            else{
                broom* cur = new broom;
                cur = node->next[i];
                node->next[i] = NULL;
                for (int j=0; j<N; j++){
                    if (cur->next[j] != NULL){
                        if (node->next[j] == NULL){
                            node->next[j] = cur->next[j];
                        }
                        //else
                    }
                }
            }
        }
    }
}*/
