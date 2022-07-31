#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    queue<int> qProg;
    queue<int> qSpeeds;
    vector<int> answer;

    int progressesSize = progresses.size();

    for (int index = 0; index < progressesSize; index++)
    {
        qProg.push(progresses[index]);
        qSpeeds.push(speeds[index]);
    }
    
    int time = 0;
    int successCount = 0;
    while (!qProg.empty())
    {
        // 모든 작업은 병렬로 처리되기 떄문에 time변수를 공통적으로 사용
        time++;
        // 앞에 있는 작업이 100%가 되었다면 그뒤에 작업들도 100%가 넘는것이 있는지 검사하여 queue에서 빼주기
        while (qProg.front() + (qSpeeds.front() * time) >= 100)
        {
            qProg.pop();
            qSpeeds.pop();
            // 완료된 작업수 세기
            successCount++;
            if (qProg.empty())
            {
                break;
            }
        }
        // 완료된 작업이 있을때만 완료된 작업수를 answer벡터에 넣어주기
        if (successCount > 0)
        {
            answer.push_back(successCount);
            successCount = 0;
        }
    }
    return answer;
}