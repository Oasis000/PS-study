def solution(wallpaper): #그리디
    answer = []
    # 파일의 수를 세어 준다.
    file1, file2 = [], []
    
    for _ in range(len(wallpaper)):
        for i in range(len(wallpaper[0])):
            if(wallpaper[_][i]=='#'):
                file1.append(_)
                file2.append(i)
    answer.append(min(file1))
    answer.append(min(file2))
    answer.append(max(file1)+ 1)
    answer.append(max(file2) + 1)
    
    return answer