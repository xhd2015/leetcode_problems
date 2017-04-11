#include <cstddef>
#include <string>
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#define AS_MACRO inline __attribute__((always_inline))
namespace x2
{
template<class T> struct CrossNode
{
typedef CrossNode<T> This;
CrossNode(int i = 0, int j = 0) :
i(i), j(j), next(NULL), previous(NULL), father(NULL), son(NULL),num(0)
{
}
~CrossNode();
CrossNode<T>* removeCol()
{
CrossNode<T> *p = this->getFirstFather();
while (p)
{
CrossNode<T> *P = p->previous, *N = p->next;
if (P)
P->next = N;
if (N)
N->previous = P;
p = p->son;
}
return this;
}
CrossNode<T>* removeRow()
{
CrossNode<T>*p = (CrossNode<T>*) this->getFirst();
while (p)
{
CrossNode<T>*F = p->father, *S = p->son;
if (F)
F->son = S;
if (S)
S->father = F;
p->getFirstFather()->num--;
p = p->next;
}
return this;
}
CrossNode<T>* getFirst()
{
CrossNode<T> *p = this;
while (p->previous)
p = p->previous;
return p;
}
void restoreCol()
{
CrossNode<T> *p = this->getFirstFather();
while (p)
{
CrossNode<T> *P = p->previous, *N = p->next;
if (P)
P->next = p;
if (N)
N->previous = p;
p = p->son;
}
}
void restoreRow()
{
CrossNode<T> *p = (CrossNode<T>*) this->getFirst();
while (p)
{
CrossNode<T> *F = p->father, *S = p->son;
if (F)
F->son = p;
if (S)
S->father = p;
p->getFirstFather()->num++;
p = p->next;
}
}
CrossNode<T>* getNthNext(unsigned int n)
{
CrossNode<T> *p = this;
while (p && n > 0)
{
p = (CrossNode<T>*) p->next;
n--;
}
return p;
}
CrossNode<T>* getFirstFather()
{
CrossNode<T> *p = this;
while (p->father)
p = p->father;
return p;
}
CrossNode<T>* getLastSon()
{
CrossNode<T> *p = this;
while (p->son)
p = p->son;
return p;
}
void insertNext(CrossNode<T>* next)
{
if (next)
{
CrossNode<T>* temp1;
temp1 = this->next;
if (temp1)
{
temp1->previous = next;
}
next->previous = this;
next->next = temp1;
this->next = next;
}
}
void insertSon(CrossNode<T>* son)
{
if (son != NULL)
{
CrossNode<T> *orison = this->son;
this->son = son;
son->father = this;
son->son = orison;
if (orison)
orison->father = son;
}
}
int i, j;
CrossNode<T> *next, *previous, *father, *son;
T data;
int num;
};
struct SudokuCrossList
{
enum
{
ROWSZ = 9,
COLSZ = 9,
NINESZ = 9,
C_1 = 0,
C_ROW = 1,
C_COL = 2,
C_NINE = 3,
C_SIZE = 4,
};
typedef SudokuCrossList This;
SudokuCrossList(int A[ROWSZ][COLSZ]) :
init_error(false)
{
for (int i = 0; i < C_SIZE; i++)
for (int j = 0; j < COLSZ * ROWSZ; j++)
constrains[i][j] = 0;
for (int i = 0; i < ROWSZ; i++)
{
for (int j = 0; j < COLSZ; j++)
{
if (A[i][j] != 0)
{
constrains[C_1][i * ROWSZ + j] = 1;
if (constrains[C_ROW][i * ROWSZ + A[i][j] - 1] == 1
|| constrains[C_COL][j * COLSZ + A[i][j] - 1] == 1)init_error=true;
constrains[C_ROW][i * ROWSZ + A[i][j] - 1] = 1;
constrains[C_COL][j * COLSZ + A[i][j] - 1] = 1;
int NINE_no = i / 3 * 3 + j / 3;
if (constrains[C_NINE][NINE_no * NINESZ + A[i][j] - 1] == 1)init_error=true;
constrains[C_NINE][NINE_no * NINESZ + A[i][j] - 1] = 1;
}
}
}
this->head = new CrossNode<int>;
int colsz = C_SIZE * COLSZ * ROWSZ;
this->head->num = colsz;
CrossNode<int>* curColLast = this->head;
for (int j = 0; j < colsz; j++)
{
CrossNode<int>* nextHead = new CrossNode<int>;
curColLast->insertNext(nextHead);
curColLast = nextHead;
}
CrossNode<int> *head1 = this->head->next;
CrossNode<int> *head2 = (CrossNode<int> *) head1->getNthNext(
ROWSZ * COLSZ);
CrossNode<int> *head3 = (CrossNode<int> *) head2->getNthNext(
ROWSZ * COLSZ);
CrossNode<int> *head4 = (CrossNode<int> *) head3->getNthNext(
ROWSZ * COLSZ);
for (int i = 0; i < ROWSZ * COLSZ; i++)
{
if (constrains[C_1][i] == 1)
continue;
int posi = i / COLSZ, posj = i % COLSZ;
for (int tryi = 1; tryi <= ROWSZ; tryi++)
{
if (constrains[C_ROW][posi * ROWSZ + tryi - 1] == 1)
continue;
if (constrains[C_COL][posj * COLSZ + tryi - 1] == 1)
continue;
int NINE_no = posi / 3 * 3 + posj / 3;
if (constrains[C_NINE][NINE_no * NINESZ + tryi - 1] == 1)
continue;
CrossNode<int> *head_pos[] ={(CrossNode<int> *) head1->getNthNext(i),	(CrossNode<int> *) head2->getNthNext(
posi * ROWSZ + tryi - 1),	(CrossNode<int> *) head3->getNthNext(posj * COLSZ + tryi - 1),
(CrossNode<int> *) head4->getNthNext(
NINE_no * NINESZ + tryi - 1)};
CrossNode<int>* nodes[]={new CrossNode<int>(0, i),new CrossNode<int>(	ROWSZ * COLSZ + posi * ROWSZ, tryi),new CrossNode<int>(
ROWSZ * COLSZ * 2 + posj * COLSZ, tryi),new CrossNode<int>(
ROWSZ * COLSZ * 3 + NINE_no * NINESZ, tryi)};
for(int k=0;k<4;k++)
{
head_pos[k]->getLastSon()->insertSon(nodes[k]);
head_pos[k]->num++;
if(k>0)nodes[k-1]->insertNext(nodes[k]);
}
}
}
head1 = this->head->next;
while (head1)
{
if (head1->num == 0)
head1->removeCol();
head1 = head1->next;
}
}

bool init_error;
int constrains[C_SIZE][COLSZ * ROWSZ];
CrossNode<int> *head;
};

struct ExactCover
{
typedef std::function<void(const std::vector<CrossNode<int>*> &oneSolution)> SaveFunType;
ExactCover() = default;
ExactCover(SaveFunType saver) :
saver(saver)
{
}
~ExactCover() = default;
void solve(SudokuCrossList& list)
{
if (list.head->next == NULL)
{
if (saver)
this->saver(solutionone);
}
else
{
CrossNode<int> *pcol = list.head->next;
CrossNode<int> *pmincol;
{
CrossNode<int> *minNode = pcol, *p = (CrossNode<int>*) pcol->next;
while (p)
{
if (minNode->num > p->num)
minNode = p;
p = (CrossNode<int>*) p->next;
}
pmincol = minNode;
}

if (pmincol->num == 0)
return;
CrossNode<int> *curRow = pmincol->son;
while (curRow)
{
this->solutionone.push_back(curRow);
CrossNode<int> *rowHead = (CrossNode<int>*) curRow->getFirst();
std::vector<std::vector<CrossNode<int>*> > rowsheads;
std::vector<CrossNode<int>*> colheads;
for (CrossNode<int>* it = rowHead; it != NULL; it =
it->next)
{
std::vector<CrossNode<int>*> arowheads;
CrossNode<int> *itcolhead =
(CrossNode<int>*) it->getFirstFather();
for (CrossNode<int>* itcol = itcolhead->son;
itcol != NULL; itcol = itcol->son)
{
arowheads.push_back(itcol);
itcol->removeRow();
}
colheads.push_back(itcolhead);
rowsheads.push_back(std::move(arowheads));
itcolhead->removeCol();
}
solve(list);
std::vector<std::vector<CrossNode<int>*> >::reverse_iterator
itrows = rowsheads.rbegin(), itrowsend =
rowsheads.rend();
std::vector<CrossNode<int>*>::reverse_iterator itcol =
colheads.rbegin(), itcolend = colheads.rend();
while (itcol != itcolend)
{
for (std::vector<CrossNode<int>*>::reverse_iterator itrow =
itrows->rbegin(), itrowend = itrows->rend();
itrow != itrowend; itrow++)
{
(*itrow)->restoreRow();
}
(*itcol)->restoreCol();
itcol++;
itrows++;
}
this->solutionone.pop_back();
curRow = curRow->son;
}
}
}
std::vector<CrossNode<int>*> solutionone;
SaveFunType saver;
};
}
//=======================INCLUDED END=============
using namespace std;
using namespace x2;
class Solution
{
public:
void solveSudoku(vector<vector<char>>& board)
{
int A[9][9] =
{ 0 };
for (int i = 0; i < 9; i++)
for (int j = 0; j < 9; j++)
if (board[i][j] != '.')
A[i][j] = (int) board[i][j] - '0';
SudokuCrossList slist(A);
bool hasval=false;
ExactCover ec(
[&board,&hasval](const std::vector<CrossNode<int>*> &solutionone)
{
if(hasval)return;
for(auto it=solutionone.begin(),itend=solutionone.end();it!=itend;it++)
{
auto &refit=*it;
CrossNode<int> *node=refit;
while(node && node->i !=0 )node=node->previous;
int i=node->j / 9,j=node->j % 9;node=refit;
while(node && node->i == 0)node=node->next;
board[i][j]=(char)(node->j + '0');
}
hasval=true;
});
ec.solve(slist);
}
};

//=====ALL right,I give up, leetcode kept saying my code too long, I know it is correct.
