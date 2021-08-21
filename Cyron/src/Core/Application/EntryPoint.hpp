#pragma once

extern Cyron::Application* Cyron::CreateApplication();


int main() {
    auto app = Cyron::CreateApplication();

    app->Run();

    delete app;
}