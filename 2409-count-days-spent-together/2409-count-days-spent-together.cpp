class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int alice_arrive_month = stoi(arriveAlice.substr(0, 2));
        int alice_arrive_day = stoi(arriveAlice.substr(3, 2));

        int alice_leave_month = stoi(leaveAlice.substr(0, 2));
        int alice_leave_day = stoi(leaveAlice.substr(3, 2));

        int bob_arrive_month = stoi(arriveBob.substr(0, 2));
        int bob_arrive_day = stoi(arriveBob.substr(3, 2));

        int bob_leave_month = stoi(leaveBob.substr(0, 2));
        int bob_leave_day = stoi(leaveBob.substr(3, 2));

        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto convertToDay = [&](int month, int day) {
            for (int i = 0; i < month - 1; i++) {
                day += days[i];
            }
            return day;
        };

        int alice_arrive = convertToDay(alice_arrive_month, alice_arrive_day);
        int alice_leave = convertToDay(alice_leave_month, alice_leave_day);

        int bob_arrive = convertToDay(bob_arrive_month, bob_arrive_day);
        int bob_leave = convertToDay(bob_leave_month, bob_leave_day);

        int start = max(alice_arrive, bob_arrive);
        int end = min(alice_leave, bob_leave);

        return max(0, end - start + 1);
    }
};