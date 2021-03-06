# groom_level
https://level.goorm.io/l/official/algorithm/dfsBfs


## Finding Shortest (L5)
1. 문제: N X N 배열 에서 시작점 (0,0) 에서 (N-1,N-1) 까지의 거리를 구하여야함.
        1: WALL
        2: PATHWAY
2. INPUT: N과 Array 정보
3. Output: the shortest path from 0,0 to n-1,n-1
4. 해결 : bfs이므로 queue를 사용하려하였으나, shortest path를 구하는 문제인 만큼 다시 돌아와야하는 부분에서 고생을 하였다.
            따라서, recursion을 사용. 만약 움직일때, true면 path++, else path -- 하면 되므로 손쉬웠다.
             Queue를 해도 푸는 것은 가능한 것으로 보이나 복잡해 보여서 현 상태론 스킵함.
          
## Prime Cycle (L5)
1. 문제: 1부터 N까지 숫자가 있는 사이클이 있습니다. 양옆 숫자 2개의 합이 모두 소우일 경우, print 합시다.
2: variables: 
        
        -- input-----------------------------------------
        a. cycle 의 숫자 갯수
       
3. 해결: next_permutation을 사용했습니다. 그 후, checkPrime function을 제작하여, 완벽탐색을 구현하면 됩니다.

## Domino Game (L3)
1. 문제: a개의 도미노가 존재. b줄에 걸쳐 각각의 도미노 번호가 쓰러뜨리는 그 다음 번호를 설정. C줄에 걸쳐 손으로 직접 쓰러뜨리는 도미노 설정.
2. Input: 첫번째 줄에 a,b,c ; 두번째 줄부터 총 b개의 줄까지 각각 두개의 도미노를 설정하는데, 첫번째 도미노가 그 다음 도미노를 쓰러뜨림.
          그 다음줄부터 총 c개까지의 줄까지 손으로 떨어뜨리는 도미노 설정
3. output: the total number of domino that is dropped.
4. variables : 
              -- input -----------------------------------------------------------
             
              a: (int) 도미노의 갯수 --> input
              b: (int) 도미노가 쓰러뜨리는 도미노의 줄 --> input
              c: (int) 직접 손으로 쓰러뜨릴 도미노의 갯수 --> input
              x: (int) b줄에 걸쳐 쓰러질 도미노 --> input
              y:(int) b줄에 걸쳐 x에 의해 쓰러질 도미노--> input
              start:(int) startVec에 넣기전, 쉽게 cin 하기위해 temp variable --> input
              m: b에서 얻은 정보들을 이용하여 m[x] = y로 설정함. 
              
              -- output ---------------------------------------------------------------
              answer:(int) the total dominoes which are dropped
              tempNum:(int) 그 다음 쓰러질 도미노를 point 하는 temp variable
              drop: (bool array[a]) 넘어진 도미노를 중복 계산하지 않기 위해 설정 
              startVec: (vector<int>) 손으로 쓰러뜨릴 도미노가 C>0 개 이므로 vector사용함
           
5. 해결: 먼저 map<pair<int,int>>를 사용하였다. 다행히도 중복된 도미노는 없어서 쉬웠다. (만약 하나의 도미노가 여러개의 도미노를 쓰러뜨렸으면 그건 map<pair<int,vector<int>>> 를 사용할 듯)
        그 후, c개의 손으로 떨어뜨리는 도미노를 vector<int>에 넣어 asceding sorting 하였다. (#include <algorithm>)
        while loop을 사용해 만약 쓰러뜨리고자한 도미노가 살아있다면 그 안에 loop을 넣어 더 이상 없을 때까지 loop을 돌리고 넘어진 것은 따로 bool array에 넣어 true로 설정하였다.
        만약 더 이상 쓰러뜨릴것이 없다면 loop을 나와 bool array 에서 true 인것을 count하면 끝.
        
## Sum of the numbers in the specific range (L3)
1. 문제: n개의 숫자를 받은 후, 특정 구간의 숫자들을 합함
2. 해결: 사실 쓸시간도 아까워서 중간과정 생략. 너무 쉬운 문제임.
           사실, dynamic programming으로 분류되어있는데 그렇게 푸는 방법은 찾는 중

## Padovan sequence (L3)
1. 문제: 파도반 수열을 이용해 n번째의 정보를 얻어야함
2. 해결: 쉬움. 피보나치와 비슷한데, fib(n) = fib(n-1) + fib(n-2)하는 반면 padovan은 pad(n) = pad(n-2) + pad(n-3)만 사용

## Frog 2 (L4)
1. 문제: 개구리 왕눈이가 주어진 돌들을 뛰어다닙니다. 근데왕눈이의 체력이 P이라면, 최대 p거리의 돌까지 뛸 수 있다.
         하지만, 점프를 할때마다, 체력이 1씩 떨어집니다. 이때의 최소 체력을 구하시오.
2. variables:
       --
       
       -- input -------------------------------------------------------
       1. N : (int) 돌의 갯수
       2. temp: (int) temp variables
       3. v: (int array) 돌의 위치
       -- output -----------------------------------------------------
       1. answer: (int) 체력 p
       
3. 해결: 뒤에서부터 돌들간의 거리를 구합니다. 그 후, 가장 큰 거리를 answer라고 하고
        항상 1을 더합니다.
        사실 처음 부터 하였을때는 틀렸다고 나왔지만, 뒤에서 부터 하니 해결되었습니다.
        
## Finding triangle Path(L3)
1. 문제: 0,0부터 시작하여 삼각형 가장 밑변으로 내려갈때 최댓값을 구하시오
2. 해결: dynamic programming을 사용하면됨. 많이 해봐서 패스.

## LIS (LIS)
1. 문제: 
2. 해결: two pointer

## Amusement Park (L2)
1. 문제: 주어진 K안에서 최소 갯수의 폐기물을 처리하자
2. Variables:
        --
        
        --input ---------------------------------------------------------
        1. waste : N X N array안에 있는 핵 폐기물의 갯수를 저장
        2. N: array의 변의 길이
        3. K : 원하는 K X K 의 갯수를 구함
        -- output -------------------------------------------------------
        1. answer: count 중 가장 작은 count
        2. count: temp variable --> K X K 안에 있는 폐기물의 갯수
        
3. 해결: 그냥 처음부터 완전 탐색을 하였습니다. 단지 우리개 해야할 일은
         K X K 의 구역의 첫 index를 포인트만 해주면되고,그 안에 또 nested loop를 사용해
         폐기물을 다 더 하면 됩니다.

## check Prime(L2)
1. 문제: number를 받고 그 숫자가 소수인지 판명
2. variables: 
        --
        
        --input ------------------------------------------------------
        1. num : 우리가 판명해야하는 숫자

3. 해결: for loop을 이용하여 2부터 원하는 숫자 사이에 단 하나의 숫자라도 mod를 했을때 0인경우는 prime 이 아닙니다.       

## 빙글빙글 (L2)
1. 문제 : 빙글 빙글 달팽이 같이 print해보자
2. variables:
        --
        
        --input -----------------------------------------------------
        1. num: 빙글 빙글의 변의 길이
        
3. 해결: 패턴만 찾으면 쉬운 문제입니다. 가장 처음의 숫자 제외하면 다 2번씩 숫자가 나오는걸 알수 있습니다.
          따라서 처음 num변만 3번이고 그 다음은 num -=2 를 두번씩 vector에 방향과 함께 넣습니다.
          다른 문제와 다르게 이 문제는 col에서 space가 존재하기 때문에 num 이 3이상일때까지 2번 넣습니다.
          그러면 vector의 처음부터 끝까지를 array에 넣으면 됩니다.

## 황제의 몰락 (L5)
1. 문제: 병사들이 원으로 둘러싸있고 자신으로부터 k번째 사람을 총으로 쏩니다.
         그 중, 두명만 남았을 경우 그만둡니다.
         남은 두 사람의 번호를 print out합니다.
2. variables:
        --
        
        --input ----------------------------------------------------
        1. N : 병사의 수
        2. K : 쏴야할 순서
        --output ---------------------------------------------------
        1. v : 순서 K

3. 해결: 그냥 vector에 1 부터 끝까지 N까지 넣습니다. 그 후, pos = 0 에 K씩 더해 vector에서 지웁니다.
        해당 vector의 사이즈가 2이상인 경우, 끝내고 남는 숫자를 프린트합니다.

## 나이트의 이동(L5)
1. 문제: 특정 모양으로 밖에 움직이지 못하는 기사가 원하는 포인트로 움직일 수 있는 최단거리를 구해야합니다.
2. 해결: 최단 거리 문제이므로, bfs를 사용하였습니다.
         그러므로 queue를 사용했지만, 2번문제는 l이 100이므로 계속 에러가 떴습니다.
         그 이유는 queue<pair<pair<int,int>,int>>를 사용해서였습니다. // q.first.first = x , q.first.second = y, q.second = dist
         따라서 chess판에 거리를 기입하므로 queue<pair<int,int>> 로 바꾸었더니 잘 움직였습니다.
