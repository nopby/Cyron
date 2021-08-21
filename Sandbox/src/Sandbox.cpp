#include <Cyron.hpp>

class Sandbox : public Cyron::Application {
public:
    Sandbox() {

    }
    ~Sandbox() {

    }
};

Cyron::Application* Cyron::CreateApplication() {
    return new Sandbox();
}