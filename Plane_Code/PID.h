#pragma once

class PID {
public:
    float p = 0;
    float i = 0;
    float d = 0;
    float limit = 0;

    float derivative = 0;
    float integral = 0;

    PID(float p, float i, float d, float limit = 0) : p(p), i(i), d(d), limit(limit)  {};

    float update(float error, float dt) {
        integral += error * dt;

        if (isfinite(prevError) && dt > 0) {
            derivative = (error - prevError) / dt;
        }

        prevError = error;

        return p * error + constrain(i * integral, -limit, limit) + d * derivative; // PID
    }

    void reset() {
        prevError = NAN;
        integral = 0;
        derivative = 0;
    }

private:
    float prevError = NAN;
};
