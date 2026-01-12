class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>radiantQ , direQ;
        int position = 0;
        for(;position<senate.size();position++){
            char senator = senate[position];
            if(senator == 'R')
                radiantQ.push(position);
            if(senator == 'D')
                direQ.push(position);
        }
        while(!radiantQ.empty() && !direQ.empty()){
            int rfront = radiantQ.front();
            radiantQ.pop();
            int dfront = direQ.front();
            direQ.pop();
            if(rfront < dfront){
                radiantQ.push(position++);
            }
            else{
                direQ.push(position++);
            }
        }
        if(!radiantQ.empty())return "Radiant";
        return "Dire";
    }
};