#include "consolerenderer.hpp"
#include <iostream>
#include <iomanip>

ConsoleRenderer::ConsoleRenderer(Game& game)
    : game_(&game)
{
    Subscribe();  
}

void ConsoleRenderer::DrawMessage(const std::string& msg) {
    std::cout << msg << "\n";
}

void ConsoleRenderer::DrawField() {
    const auto& field = game_->getField();
    int width  = field.getWidth();
    int height = field.getHeight();
    for (int x = 0; x < width; ++x) {
        std::cout << std::setw(2) << std::setfill('0') << x << " ";
    }
    std::cout << "\n";
    for (int y = 0; y < height; ++y) {
        std::cout << std::setw(2) << std::setfill('0') << y << "  ";
        for (int x = 0; x < width; ++x) {
            DrawCell(field.At(x, y).getType());
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void ConsoleRenderer::DrawCell(CellType type) {
    switch (type) {
        case CellType::kEmpty:     std::cout << " . ";   break;
        case CellType::kPlayer:    std::cout << " 🔬";   break;
        case CellType::kEnemy:     std::cout << " 👽";   break;
        case CellType::kWall:      std::cout << " 🧱";   break;
        case CellType::kBuilding:  std::cout << " 🛸";   break;
        case CellType::kSlow:      std::cout << " 🌀";   break;
        case CellType::kTrap:      std::cout << " 💣";   break;
        case CellType::kAlly:      std::cout << " 🤖";   break;
        case CellType::kTower:     std::cout << " 🏰";   break;
        default:                   std::cout << " ❓";   break;
    }
}

void ConsoleRenderer::Subscribe()
{
    auto& disp = EventDispatcher::instance();

    disp.subscribe<UiMessageEvent>([this](const UiMessageEvent& ev) {
        DrawMessage(ev.text);
    });

    disp.subscribe<TurnCompletedEvent>([this](const TurnCompletedEvent&) {
        DrawField();
    });
}

