#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
#define MAX 112345
typedef vector<int> vi;
typedef pair<int, int> ii;

int N; // |V(G)|
int vis[MAX]; // DFS
int tp[MAX], t; // toposort
int comp[MAX], ncomp; // componentes conexas
int S[MAX], top, instack[MAX]; // Tarjan stack
int order[MAX], cycle[MAX], gorder;

void tarjan(vector<vi> &LG, int u) {
  int i, v;
  S[top++] = u; instack[u] = 1;
  order[u] = cycle[u] = gorder++;
  for (i = 0; i < (int) LG[u].size(); i++) {
    v = LG[u][i];
    if (!order[v]) tarjan(LG, v);
    if (instack[v]) cycle[u] = min(cycle[u], cycle[v]); }
  if (order[u] == cycle[u]) {
    do {
      v = S[--top]; instack[v] = 0;
      comp[v] = ncomp; }
    while (v != u);
    ncomp++; }}

void dfs(vector<vi> &LDAG, int u) {
  int i;
  vis[u] = 1;
  for (i = 0; i < (int) LDAG[u].size(); i++)
    if (!vis[LDAG[u][i]])
      dfs(LDAG, LDAG[u][i]);
  tp[t++] = u; }

int main(void) {
  bool semi;
  int M, U, V, i;
  semi = true; t = 0;
  gorder = 1; ncomp = top = 0;
  memset(vis, 0, sizeof vis);
  memset(order, 0, sizeof order);
  memset(cycle, 0, sizeof cycle);
  memset(instack, 0, sizeof instack);
  scanf("%d %d", &N, &M);
  vector<vi> LG(N);
  while (M--) {
    scanf("%d %d", &U, &V); U--; V--;
    LG[U].push_back(V); }
  for (U = 0; U < N; U++)
    if (!order[U]) tarjan(LG, U);
  vector<vi> LDAG(ncomp); // L(DAG)
  set<ii> EDAG; // edge set for DAG
  for (U = 0; U < N; U++) {
    for (i = 0; i < (int) LG[U].size(); i++) {
      V = LG[U][i];
      if (comp[U] != comp[V]) {
	LDAG[comp[U]].push_back(comp[V]);
	EDAG.insert(ii(comp[U], comp[V])); }}}
  for (U = 0; U < ncomp; U++)
    if (!vis[U]) dfs(LDAG, U);
  for (i = t - 1; semi && i > 0; i--)
    if (EDAG.find(ii(tp[i], tp[i - 1])) == EDAG.end())
      semi = false;
  printf("%sBolada\n", semi ? "" : "Nao ");
  return 0; }