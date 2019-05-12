#Segment tree

기존에 배운 부분합은 중간에 값이 변경될 경우 사용될 수 없음.
sparse table 또한 값이 변경될 경우 사용할 수 없음.

세크먼트 트리는 이진 트리.

``
root: 29
- child: 16
	- child: 5
		- child: 1
		- child: 4
	- child: 11
		- child: 3
		- child: 8
- child: 13
	- child: 5
		- child: 2
		- child: 3
	- child: 8
		- child: 6
		- child: 2
``

leaf 노드에는 값 그 자체를 넣는다.
부모는 자식의 합을 저장한다.


각 노드는 합과 포함하고 있는 구간에 대한 정보를 가지고 있다.

처음 트리 생성시   : O(N log N)
쿼리 시간복잡도    : O(log N)
값 변경 시간복잡도 : O(log N)
