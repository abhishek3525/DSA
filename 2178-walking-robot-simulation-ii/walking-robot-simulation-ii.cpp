class Robot {
    int x, y;
    int dir; // 0=East, 1=North, 2=West, 3=South
    int w, h;
    int perimeter;

public:
    Robot(int width, int height) {
        x = 0;
        y = 0;
        dir = 0;
        w = width;
        h = height;
        perimeter = 2 * (w + h - 2);
    }
    
    void step(int num) {
        num %= perimeter;

        // special case
        if (num == 0 && x == 0 && y == 0) {
            dir = 3; // South
            return;
        }

        while (num--) {
            int nx = x, ny = y;

            if (dir == 0) nx++;
            else if (dir == 1) ny++;
            else if (dir == 2) nx--;
            else ny--;

            // check boundary
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                dir = (dir + 1) % 4; // turn CCW
                num++; // retry this step
            } else {
                x = nx;
                y = ny;
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        if (dir == 0) return "East";
        if (dir == 1) return "North";
        if (dir == 2) return "West";
        return "South";
    }
};