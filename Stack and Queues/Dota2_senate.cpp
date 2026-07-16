class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>QR,QD;
        for (int i = 0 ; i < senate.size() ; i++){
            if (senate[i] == 'R'){
                QR.push(i);
            }
            else{
                QD.push(i);
            }
        }
        while(!QR.empty()&&!QD.empty()){
            int r_index = QR.front();
            QR.pop();
            int D_index = QD.front();
            QD.pop();
            if (r_index > D_index){
                QD.push(r_index + senate.size());
            }
            else{
                QR.push(D_index + senate.size());
            }
        }
        return (QR.empty()?"Dire":"Radiant");
    }
};
