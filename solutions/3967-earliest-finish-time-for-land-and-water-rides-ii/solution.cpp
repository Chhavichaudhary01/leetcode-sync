class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long minLandFinish = LLONG_MAX;
        for (int i = 0; i < landStartTime.size(); i++) {
            minLandFinish = min(
                minLandFinish,
                (long long)landStartTime[i] + landDuration[i]
            );
        }

        long long minWaterFinish = LLONG_MAX;
        for (int j = 0; j < waterStartTime.size(); j++) {
            minWaterFinish = min(
                minWaterFinish,
                (long long)waterStartTime[j] + waterDuration[j]
            );
        }

        long long ans = LLONG_MAX;

        // Land -> Water
        for (int j = 0; j < waterStartTime.size(); j++) {
            ans = min(
                ans,
                max((long long)waterStartTime[j], minLandFinish)
                    + waterDuration[j]
            );
        }

        // Water -> Land
        for (int i = 0; i < landStartTime.size(); i++) {
            ans = min(
                ans,
                max((long long)landStartTime[i], minWaterFinish)
                    + landDuration[i]
            );
        }

        return (int)ans;
    }
};
