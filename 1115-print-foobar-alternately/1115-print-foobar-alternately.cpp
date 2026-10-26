class FooBar {
private:
    int n;
    int t = 0;

    mutex m;
    condition_variable cv;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);

            cv.wait(lock, [this] {
                return t == 0;
            });

            printFoo();
            t = 1;

            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);

            cv.wait(lock, [this] {
                return t == 1;
            });

            printBar();
            t = 0;

            cv.notify_all();
        }
    }
};