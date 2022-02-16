
class EngineBox;

class EngineState {
    public:
        virtual void up(EngineBox* pEBoX) = 0;
        virtual void down(EngineBox* pEBoX) = 0;
        virtual void showCurrentState() = 0;
};

class EngineBox {
    public:
        EngineBox();
        void up ();
        void down ();
        void nowState ();
        void changeState (EngineState *newState);
    private:
        EngineState* state;
};


class EngineIdle : public EngineState {
    public:
        void up(EngineBox* pEBoX);
        void down(EngineBox* pEBoX);
        void showCurrentState();
};

class EngineRunningLow : public EngineState {
    public:
        void up(EngineBox* pEBoX);
        void down(EngineBox* pEBoX);
        void showCurrentState();
};

class EngineRunningHigh : public EngineState {
    public:
        void up(EngineBox* pEBoX);
        void down(EngineBox* pEBoX);
        void showCurrentState();
};
