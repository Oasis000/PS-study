def solution(n, s):
    answer = []
    for _ in range(n):
        answer.append(s//n)

    if(n%s != 0):
        for _ in range(s - (s//n)*n):
            answer[_]=answer[_]+1
    answer.sort()
    if(answer[0]==0):
            answer=[-1]
    return answer