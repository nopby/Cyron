#pragma once

namespace Cyron {

    class Application {
        public:
            Application();
            ~Application();
            void Run();
        private:
            static Application* s_Instance;
    };
    Application* CreateApplication();
}
