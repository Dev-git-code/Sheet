```table-of-contents
title: 
style: nestedList # TOC style (nestedList|nestedOrderedList|inlineFirstLevel)
minLevel: 0 # Include headings from the specified level
maxLevel: 0 # Include headings up to the specified level
include: 
exclude: 
includeLinks: true # Make headings clickable
hideWhenEmpty: false # Hide TOC if no headings are found
debugInConsole: false # Print debug info in Obsidian console
```
# Basic DP topics 

Programming in Dynamic programming means table generation, so DP actually means Dynamic table generation.
## Principle of Optimality - Dynamic Programming introduction

```embed
title: "YouTube"
image: "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAeAAAAFoCAYAAACPNyggAAAOn0lEQVR4Xu3VsQnDQBBFwd3AakTuv8UTOHQuXjJXwC0MH97OzBmPAAECBAgQeFVgd+ecM/f9nev6zArwq94+J0CAAAECPwEBNgQCBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBD4D/ADV99NUy08rgcAAAAASUVORK5CYII="
description: "Share your videos with friends, family, and the world"
url: "https://youtu.be/5dRGRueKU3M?si=2goWpsNrXEoP_AQi"
```

- In greedy, decision is taken one time and we follow that procedure. Whereas, in DP, every stage we take a decision. 
- **Memoization** follows **top down approach:** we started from 5 and then called smaller numbers.
- ![[5f60f571199b52c2520b7bf645c8454a_MD5.png]]

- We don't use memoization often in DP, but it reduces the TC in the above case from 2^n to n.
- In DP, we use iterative method called **Tabulation method**
- ![[14734bd955346edc005cf7482458a054_MD5.png]]

- Here we wanted 5, we started from 0 onwards and reached 5, so this is **Bottom Up Approach.** 

## Multi-Stage Graph

```embed
title: "4.1 MultiStage Graph - Dynamic Programming"
image: "https://img.youtube.com/vi/9iE9Mj4m8jk/maxresdefault.jpg"
description: "Multistage Graph ProblemSolved using Dynamic ProgrammingForward MethodPATREON : https://www.patreon.com/bePatron?u=20475192Courses on Udemy================Ja…"
url: "https://youtu.be/9iE9Mj4m8jk?si=jBmntxXHOQjDqbQ4"
```


![[0d651e0cc5dac8372b2387d79049d9aa_MD5.png]]

- Useful for representing resource allocation. 
- In this problem, there are various paths from source to sink and we have to select the path which is giving the minimum cost.
- Is DP applicable here? 
	- For every vertex I will have to take a decision, so here the principal of optimality holds, therefore we can use DP to solve this problem.
```embed
title: "4.1 MultiStage Graph - Dynamic Programming"
image: "https://img.youtube.com/vi/9iE9Mj4m8jk/maxresdefault.jpg"
description: "Multistage Graph ProblemSolved using Dynamic ProgrammingForward MethodPATREON : https://www.patreon.com/bePatron?u=20475192Courses on Udemy================Ja…"
url: " https://youtu.be/9iE9Mj4m8jk?si=rsuSbsllhI4mBjVa"
```

```embed
title: "watch?v=FcScLYJI42E?si=WsyecFJ33bSONhja"
image: "https://img.youtube.com/vi/FcScLYJI42E/maxresdefault.jpg"
description: "Multistage graph Program and explanation PATREON : https://www.patreon.com/bePatron?u=20475192 Courses on Udemy ================ Java Programming https://www.udemy.com/course/java-se-programming/?referralCode=C71BADEAA4E7332D62B6 Data Structures using C and C++ https://www.udemy.com/course/datastructurescncpp/?referralCode=BD2EF8E61A98AB5E011D C++ Programming https://www.udemy.com/course/cpp-deep-dive/?referralCode=E4246A516919D7E84225"
url: "https://youtu.be/FcScLYJI42E?si=WsyecFJ33bSONhja"
```


### Code: 

```cpp
// CPP program to find shortest distance
// in a multistage graph.
#include<bits/stdc++.h>
using namespace std;

#define N 8
#define INF INT_MAX

// Returns shortest distance from 0 to
// N-1.
int shortestDist(int graph[N][N]) {

	// dist[i] is going to store shortest
	// distance from node i to node N-1.
	int dist[N];

	dist[N-1] = 0;

	// Calculating shortest path for
	// rest of the nodes
	for (int i = N-2 ; i >= 0 ; i--)
	{

		// Initialize distance from i to
		// destination (N-1)
		dist[i] = INF;

		// Check all nodes of next stages
		// to find shortest distance from
		// i to N-1.
		for (int j = i ; j < N ; j++)
		{
			// Reject if no edge exists
			if (graph[i][j] == INF)
				continue;

			// We apply equation to
			// distance to target through j.
			// and compare with minimum distance 
			// so far.
			dist[i] = min(dist[i], graph[i][j] +
										dist[j]);
		}
	}

	return dist[0];
}

// Driver code
int main()
{
	// Graph stored in the form of an
	// adjacency Matrix
	int graph[N][N] =
	{{INF, 1, 2, 5, INF, INF, INF, INF},
	{INF, INF, INF, INF, 4, 11, INF, INF},
	{INF, INF, INF, INF, 9, 5, 16, INF},
	{INF, INF, INF, INF, INF, INF, 2, INF},
	{INF, INF, INF, INF, INF, INF, INF, 18},
	{INF, INF, INF, INF, INF, INF, INF, 13},
	{INF, INF, INF, INF, INF, INF, INF, 2},
	{INF, INF, INF, INF, INF, INF, INF, INF}};

	cout << shortestDist(graph);
	return 0;
}

```
```embed
title: "Multistage Graph (Shortest Path) - GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/uploads/multi-stage-graph.jpg"
description: "A Computer Science portal for geeks. It contains well written, well thought and well explained computer science and programming articles, quizzes and practice/competitive programming/company interview Questions."
url: "https://www.geeksforgeeks.org/multistage-graph-shortest-path/"
```

## All Pairs Shortest Path 

```embed
title: "watch?v=oNI0rf2P9gE"
image: "https://img.youtube.com/vi/oNI0rf2P9gE/maxresdefault.jpg"
description: "Floyd-Warshall All Pairs Shortest Path Problem Dynamic Programming PATREON : https://www.patreon.com/bePatron?u=20475192 Courses on Udemy ================ Java Programming https://www.udemy.com/course/java-se-programming/?referralCode=C71BADEAA4E7332D62B6 Data Structures using C and C++ https://www.udemy.com/course/datastructurescncpp/?referralCode=BD2EF8E61A98AB5E011D C++ Programming https://www.udemy.com/course/cpp-deep-dive/?referralCode=E4246A516919D7E84225"
url: "https://www.youtube.com/watch?v=oNI0rf2P9gE"
```
- We can solve this problem using djikstra but for n nodes it will take O(n2 * n) time.
-  ![[1e6089e6cc561a09f05029a3e6f780cc_MD5.png]]

- A0 represents the shortest path if we go through no vertex.
- here A1 represents the matrix for the cost for paths going through 1,i.e. using A1 as inter-mediatory node. 
- Ak represents the shortest path if we go through the 1, 2, .... kth vertex.
- ![[eed9a2f07ac57ca50b06c67e28fd784e_MD5.png]]

### Better explanation from luv

```embed
title: "Floyd Warshall Algorithm: All Pair Shortest Path | Tutorial with Code | CP Course | EP 83"
image: "https://img.youtube.com/vi/5MEZXOyaRmk/maxresdefault.jpg"
description: "Graph/Trees Playlist : https://youtube.com/playlist?list=PLauivoElc3ghxyYSr_sVnDUc_ynPk6iXEALL CP/DSA RESOURCES : https://linktr.ee/iamluvFREE COMPETITIVE PR…"
url: " https://youtu.be/5MEZXOyaRmk?si=Id8YJectXdK3i6NY"
```

### CP Algos Article

```embed
title: "Floyd-Warshall - finding all shortest paths - Algorithms for Competitive Programming"
image: "https://cp-algorithms.com/favicon.ico"
description: "The goal of this project is to translate the wonderful resource http://e-maxx.ru/algo which provides descriptions of many algorithms and data structures especially popular in field of competitive programming. Moreover we want to improve the collected knowledge by extending the articles and adding new articles to the collection."
url: "https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html"
```

### Code: 
```cpp
// C++ Program for Floyd Warshall Algorithm
#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 4

/* Define Infinite as a large enough
value.This value will be used for
vertices not connected to each other */
#define INF 99999

// A function to print the solution matrix
void printSolution(int dist[][V]);

// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm
void floydWarshall(int dist[][V])
{

	int i, j, k;

	/* Add all vertices one by one to
	the set of intermediate vertices.
	---> Before start of an iteration,
	we have shortest distances between all
	pairs of vertices such that the
	shortest distances consider only the
	vertices in set {0, 1, 2, .. k-1} as
	intermediate vertices.
	----> After the end of an iteration,
	vertex no. k is added to the set of
	intermediate vertices and the set becomes {0, 1, 2, ..
	k} */
	for (k = 0; k < V; k++) {
		// Pick all vertices as source one by one
		for (i = 0; i < V; i++) {
			// Pick all vertices as destination for the
			// above picked source
			for (j = 0; j < V; j++) {
				// If vertex k is on the shortest path from
				// i to j, then update the value of
				// dist[i][j]
				if (dist[i][j] > (dist[i][k] + dist[k][j])
					&& (dist[k][j] != INF
						&& dist[i][k] != INF))
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	// Print the shortest distance matrix
	printSolution(dist);
}

/* A utility function to print solution */
void printSolution(int dist[][V])
{
	cout << "The following matrix shows the shortest "
			"distances"
			" between every pair of vertices \n";
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (dist[i][j] == INF)
				cout << "INF"
					<< " ";
			else
				cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

// Driver's code
int main()
{
	/* Let us create the following weighted graph
			10
	(0)------->(3)
		|	 /|\
	5 |	 |
		|	 | 1
	\|/	 |
	(1)------->(2)
			3	 */
	int graph[V][V] = { { 0, 5, INF, 10 },
						{ INF, 0, 3, INF },
						{ INF, INF, 0, 1 },
						{ INF, INF, INF, 0 } };

	// Function call
	floydWarshall(graph);
	return 0;
}



```
[code link: ](https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/)

## Matrix Chain Multiplication 

```embed
title: "[New] Matrix Chain Multiplication using Dynamic Programming Formula"
image: "https://img.youtube.com/vi/_WncuhSJZyA/maxresdefault.jpg"
description: "Matrix Chain Multiplication using Dynamic Programming FormulaPATREON : https://www.patreon.com/bePatron?u=20475192Courses on Udemy================Java Progra…"
url: "https://youtu.be/_WncuhSJZyA?si=mavQZ5XDB4V0zJ4Y"
```

![[a3e4630817357a9d9f6a9024d3a97550_MD5.png]]

- Here find the combination which gives the least cost for multiplying these three matrices and the formula is generated from observation. 
- Dynamic programming says that `You have to try all possible combinations and pick up the best one.`
- To get all possible combination cost we need a formula, that is derived in the above ss. 
### Formula derivation

```embed
title: "[New] Matrix Chain Multiplication using Dynamic Programming Formula"
image: "https://img.youtube.com/vi/_WncuhSJZyA/maxresdefault.jpg"
description: "Matrix Chain Multiplication using Dynamic Programming FormulaPATREON : https://www.patreon.com/bePatron?u=20475192Courses on Udemy================Java Progra…"
url: "https://youtu.be/_WncuhSJZyA?t=777"
```

**`cost[i,j] = min { m[i, k] + m[k+1, j] + dims[i-1]*dims[k]*dims[j] }`**
**`where i <= k < j`**
### Code Video 

```embed
title: "watch?v=eKkXU3uu2zk?si=0FWHEQmYFHqWN52I"
image: "https://img.youtube.com/vi/eKkXU3uu2zk/maxresdefault.jpg"
description: "Matrix Chain Multiplication Program and Explanation to learn Dynamic Programming Approach visit https://youtu.be/prx1psByp7U Courses on Udemy ================ Java Programming https://www.udemy.com/course/java-se-programming/?referralCode=C71BADEAA4E7332D62B6 Data Structures using C and C++ https://www.udemy.com/course/datastructurescncpp/?referralCode=BD2EF8E61A98AB5E011D C++ Programming https://www.udemy.com/course/cpp-deep-dive/?referralCode=E4246A516919D7E84225"
url: "https://youtu.be/eKkXU3uu2zk?si=0FWHEQmYFHqWN52I"
```

#### Code 

```cpp
// Abdul Bari video code for Matrix Chain Multiplication

#include<bits/stdc++.h>
using namespace std;
#define ROW 5
#define COL 5

template<typename T>
void printMatrix(T mat) {
    cout<<"\n Printing Matrix : \n";
    for(int i=0 ; i<=ROW-1 ; i++) {
        for(int j=0 ; j<=COL-1 ; j++)
            cout<< *(*(mat+i)+j)<<" ";
        cout<<endl;
    }
    cout<<endl;
}

int main(){
   // hardcoded the matrix input values
    int n = 5;
    int P[] =  {5,4,6,2,7}; // dimensions of the maftrices
    int m[5][5] = {0}; // store the cost 
    int S[5][5] = {0}; // store the value of min k

    int j, min,q; // min is the min value for M[i][j] and q is temp for
                  // storing all the current values

    // this loop for diagonal 
    for(int d = 1;d<n-1;d++){ // d is the diff(i,j) diagonal wise
        // this loop is for the rows
        for(int i = 1;i<n-d;i++){
            j = i+d; 
            min = INT_MAX;
            // this loop is for finding cost for each value of k
            for(int k=i;k<j;k++){
                q = m[i][k] + m[k+1][j] + P[i-1]*P[k]*P[j];
                if(q<min){
                    min = q;
                    S[i][j] = k;
                }
            }
            m[i][j] = min;
        }

    }
    cout<<m[1][n-1];
    printMatrix(m);
    printMatrix(S);
    return 0;
}
```

```md
Output:

158

Printing Matrix : 
0   0    0    0    0 
0   0  120   88  158 
0   0    0   48  104 
0   0    0    0   84 
0   0    0    0    0 


Printing Matrix : 
0 0 0 0 0 
0 0 1 1 3 
0 0 0 2 3 
0 0 0 0 3 
0 0 0 0 0 

```

```cpp
// for diagonal iteration in a matrix

// this loop for diagonal 
for(int d = 1;d<n-1;d++){ // d is the diff(i,j) diagonal wise
	// this loop is for the rows
	for(int i = 1;i<n-d;i++){
	j = i+d;
	//here i and j are idx of diagonal iteration in matrix
	}
}

```
### GFG article 

```embed
title: "Matrix Chain Multiplication | DP-8 - GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/uploads/matrixchainmultiplication.png"
description: "A Computer Science portal for geeks. It contains well written, well thought and well explained computer science and programming articles, quizzes and practice/competitive programming/company interview Questions."
url: " https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/"
```

### Problem Practice `Flipkart , Microsoft`

```embed
title: "Matrix Chain Multiplication | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given a sequence of matrices, find the most efficient way to multiply these matrices together.&nbsp;The efficient way is the one that involves&nbsp;the least number of&nbsp;multiplications. The dimensions of the matrices are given in an array arr[]&"
url: " https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article"
```

```cpp
  int matrixMultiplication(int n, int arr[])
    {
        // Initialize a vector of vectors
        vector<vector<int>> m(n, vector<int>(n, 0)); // Initialize with zeros
        int j, minK, temp;
        
        for(int d = 1;d<n-1;d++){
            for(int i =1;i<n-d;i++){
                j = i+d;
                minK = INT_MAX;
                //cost[i,j] = min { m[i, k] + m[k+1, j] + dims[i-1]*dims[k]*dims[j] }`**
                //where i <= k < j
                for(int k = i;k<j;k++){
                    temp = m[i][k] + m[k+1][j] + arr[i-1]*arr[k]*arr[j];
                    minK = min(temp,minK);
                }
                m[i][j] = minK;
            }
            
        }
        return m[1][n-1];
    }
```

## Bellman Ford Algorithm 

```embed
title: "watch?v=FtN3BYH2Zes"
image: "https://img.youtube.com/vi/FtN3BYH2Zes/maxresdefault.jpg"
description: "Bellman Ford Single Source Shortest Path Dynamic Programming Drawbacks PATREON : https://www.patreon.com/bePatron?u=20475192 Courses on Udemy ================ Java Programming https://www.udemy.com/course/java-se-programming/?referralCode=C71BADEAA4E7332D62B6 Data Structures using C and C++ https://www.udemy.com/course/datastructurescncpp/?referralCode=BD2EF8E61A98AB5E011D C++ Programming https://www.udemy.com/course/cpp-deep-dive/?referralCode=E4246A516919D7E84225"
url: "https://www.youtube.com/watch?v=FtN3BYH2Zes&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=53"
```

- We have Dijkstra algorithm that will solve the shortest path problem, but it will not work incase of negative edges. 
- Bellman ford algo says that " You go on relaxing all the edges repeatedly for `n-1` times. "
### Relaxation 
![[87230bb40acb76dd8ed5124021970025_MD5.png]]
### Practice

#### Implement Bellman ford Algorithm
```embed
title: "watch?v=0vVofAhAYjc?t=1375"
image: "https://img.youtube.com/vi/0vVofAhAYjc/maxresdefault.jpg"
description: "GfG-Problem Link: https://bit.ly/3K7emug C++/Java/Codes and Notes Link: https://takeuforward.org/data-structure/bellman-ford-algorithm-g-41/ DP Series: https://www.youtube.com/watch?v=FfXoiwwnxFw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY SDE Sheet: https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/ Check out our Website for curated resources: https://www.takeuforward.org/ Our Second Channel: https://www.youtube.com/channel/UCvEKHATlVq84hm1jduTYm8g In case you are thinking to buy courses, please check below: Code “takeuforward” for 15% off at GFG: https://practice.geeksforgeeks.org/courses Code “takeuforward” for 20% off on sys-design: https://get.interviewready.io?_aff=takeuforward Crypto, I use the Wazirx app: https://wazirx.com/invite/xexnpc4u Take 750 rs free Amazon Stock from me: https://indmoney.onelink.me/RmHC/idjex744 Earn 100 rs by making a Grow Account for investing: https://app.groww.in/v3cO/8hu879t0 Linkedin/Instagram/Telegram: https://linktr.ee/takeUforward ---------------------------------------------------------------------------------------------------------------------------"
url: "https://youtu.be/0vVofAhAYjc?t=1375"
```

- We get the shortest path if we apply the bellman ford algorithm for n-1 times but if the distances are updated if we apply bellman ford for one more time then negative cycle is present. 


```embed
title: "Distance from the Source (Bellman-Ford Algorithm) | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given a weighted and directed graph of V vertices and E edges, Find the shortest distance of all the vertex’s from the source vertex S. If a vertices can’t be reach from the S then mark the distance as 10^8. Note: If the Graph contains a negative cyc"
url: "https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1"
```

```cpp
 vector<int> bellman_ford(int V, vector<vector<int>>& edges, int s) {
        vector<int> d(V,1e8);
        d[s] = 0;
        for(int i = 0;i<V-1;i++){
            for(auto e:edges){
                int u = e[0];
                int v = e[1];
                int w = e[2];
                if(d[u]!=1e8 && d[u]+w<d[v]){
                    d[v] = d[u] + w;
                }
            }
        }
        // check negative cycle:
        //if the nodes are relaxed for one more time -ve cycle is present
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
           if(d[u]!=1e8 && d[u]+w<d[v]){
               return {-1};
           }
        }
        
        return d;
    }
```

- this code can be optimized using updated flag. Read the below article for that...
### Further Reading 

```embed
title: "Bellman-Ford - finding shortest paths with negative weights - Algorithms for Competitive Programming"
image: "https://cp-algorithms.com/favicon.ico"
description: "The goal of this project is to translate the wonderful resource http://e-maxx.ru/algo which provides descriptions of many algorithms and data structures especially popular in field of competitive programming. Moreover we want to improve the collected knowledge by extending the articles and adding new articles to the collection."
url: "https://cp-algorithms.com/graph/bellman_ford.html"
```

## 0/1 Knapsack 

```embed
title: "4.5 0/1 Knapsack - Two Methods - Dynamic Programming"
image: "https://img.youtube.com/vi/nLmhmB6NzcM/maxresdefault.jpg"
description: "0/1 Knapsack ProblemDynamic ProgrammingTwo Methods to solve the problemTabulation MethodSets MethodPATREON : https://www.patreon.com/bePatron?u=20475192Cours…"
url: "https://www.youtube.com/watch?v=nLmhmB6NzcM&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=55"
```

![[6eb4f06b7420d17c0859175c9058c3ae_MD5.png]]

Go through the table and imagine the whole process and then the formula can be easily understood and derived.

- We have a table for weight of knapsack and objects to be considered. 
- Now in this table the knapsack starting from weight 0 to M are considered. 
- Each row represents a object and the number of objects considered till that row. 
- So cells in each row give the optimal knapsack till that object.
- Now to get the value of each cell: 
	- we take the max of: 
		- either the cell above, which is optimal till that point for that particular knapsack value. 
		- or we put the current object in the knapsack so remaining knapsack space becomes `w - w[i]` and get the value for this remaining knapsack space from the table and finally add the profit of the object that we have considered i.e. `P[i]`. 
- Therefore each cell is given as: 
```cpp 
V[i,w] = max { V[i-1,w] , V[i-1,w-w[i]] + P[i]};
```


### Code: 

```embed
title: "4.5.1 0/1 Knapsack Problem (Program) - Dynamic Programming"
image: "https://img.youtube.com/vi/zRza99HPvkQ/maxresdefault.jpg"
description: "0/1 Knapsack Problem explained using ProgramPATREON : https://www.patreon.com/bePatron?u=20475192Courses on Udemy================Java Programminghttps://www.…"
url: "https://www.youtube.com/watch?v=zRza99HPvkQ"
```

```cpp
// abdul bari video code.
#include<bits/stdc++.h>
using namespace std;

template<typename T>
void printMatrix(T mat, int ROW, int COL) {
    for(int i=0 ; i<=ROW-1 ; i++) {
        for(int j=0 ; j<=COL-1 ; j++)
            cout<< *(*(mat+i)+j)<<" ";
        cout<<endl;
    }
    cout<<endl;
}


int main(){

    int P[5] = {0,1,2,5,6};
    int wt[5] = {0,2,3,4,5};
    int m = 8,n=4;
    int K[5][9];

    for(int i = 0;i<=n;i++){
        for(int w = 0;w<=m;w++){
            if(i==0 or w ==0) 
                K[i][w] = 0;
            else if(wt[i]<=w)
                K[i][w] = max(K[i-1][w], K[i-1][w-wt[i]] + P[i]); // knapsack formula
            else if(wt[i]>w) 
                K[i][w] = K[i-1][w];
        }
    }

    cout<<K[n][m]<<endl;
    printMatrix(K,5,9);

    return 0;

}
```

```md
// output 
8
0 0 0 0 0 0 0 0 0 
0 0 1 1 1 1 1 1 1 
0 0 1 2 2 3 3 3 3 
0 0 1 2 5 5 6 7 7 
0 0 1 2 5 6 6 7 8 
```

- To see which objects are included 
	- if the current cell value matches to the previous row cell then the current object is not included as there is no change. and then we check the upper row for the same knapsack capacity.
	- but if the current cell value does not match to the previous row cell value that means the object is included and we move to the previous row and since current object is included we subtract the weight of current object from the knapsack to get the remaining knapsack capacity and then check the same thing until we reach the 0th row and 0th column. 
```cpp
int i = n,j=m;
while(i>0 && j>0){
	if(K[i][j]==K[i-1][j]){ //object not included
		cout<<"object "<<i<<" not included"<<endl;
		i--; // check in prev row
	}
	else{
		cout<<"object "<<i<<" included"<<endl;
		i--;
		j = j-wt[i]; // check for the remaining knapsack capacity
	}
}
```

```
Output: 

object 4 included
object 3 included
object 2 not included
object 1 not included
```
### Practice `Flipkart, Morgan Stanley, Amazon, Microsoft, Snapdeal, Oracle`

```embed
title: "0 - 1 Knapsack Problem | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.In other words, given two integer arrays val[0..N-1] and wt[0..N"
url: "https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1"
```

```cpp
 int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<pair<int,int>> wt_val;
       // here 0th index represents 1st object 
       // so we use i-1 instead of i
       int K[n+1][W+1];
       for(int i = 0;i<=n;i++){
           for(int w = 0;w<=W;w++){
               if(i==0 or w==0)
                    K[i][w] = 0;
               else if (wt[i-1]<=w)
                    K[i][w] = max(K[i-1][w],K[i-1][w-wt[i-1]]+val[i-1]);
               else
                    K[i][w] = K[i-1][w];
           }
       }
       return K[n][W];
    }
```


## Travelling Salesman using DP

```embed
title: "4.7 [New] Traveling Salesman Problem - Dynamic Programming using Formula"
image: "https://img.youtube.com/vi/Q4zHb-Swzro/hqdefault.jpg"
description: "Traveling Salesman Problem - Dynamic Programming - Explained using FormulaPATREON : https://www.patreon.com/bePatron?u=20475192Courses on Udemy==============…"
url: "https://youtu.be/Q4zHb-Swzro?si=Nm0RHk-3SjjiMVZS"
```
![[bb060720c81c685ef61b50cdffbc85e5_MD5.png]]

- Recursive tree using the simple formula without DP.
### Further reading 
```embed
title: "Travelling Salesman Problem using Dynamic Programming - GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/Euler12.png"
description: "Travelling Salesman Problem (TSP): Given a set of cities and distance between every pair of cities, the problem is to find the shortest p ossible route that"
url: "https://www.geeksforgeeks.org/travelling-salesman-problem-using-dynamic-programming/"
```



