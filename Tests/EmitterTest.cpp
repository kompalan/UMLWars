#include <pch.h>
#include <gtest/gtest.h>
#include <Game.h>

/**
 * @file EmitterTest.cpp
 * @author Anurag Kompalli
 */

TEST(EmitterTest, TestNothing) {
    std::shared_ptr<Game> game = std::make_shared<Game>();
    std::shared_ptr<UMLData> data = std::make_shared<UMLData>(game.get());
    data->LoadData(L"data/uml.xml");

    std::shared_ptr<Emitter> emitter = std::make_shared<Emitter>(game.get(), data);

    const unsigned int RandomSeed = 1238197374;
    emitter->GetRandomGood().seed(RandomSeed);

    game->Update(1);
    int size = game->GetSize();
    std::cout<<size<<"\n";
    ASSERT_TRUE(size == 3);
}

TEST(EmitterTest, TestGoodClass) {
    std::shared_ptr<Game> game = std::make_shared<Game>();
    std::shared_ptr<UMLData> data = std::make_shared<UMLData>(game.get());
    data->LoadData(L"data/uml.xml");

    std::shared_ptr<Emitter> emitter = std::make_shared<Emitter>(game.get(), data);

    const unsigned int RandomSeed = 1238197374;
    emitter->GetRandomGood().seed(RandomSeed);

    emitter->SetBadThreshold(100);
    emitter->SetInheritanceThreshold(0);

    // Good Should Be Created
    game->Update(2.6);

    ASSERT_TRUE(game->GetSize() == 4);
}

TEST(EmitterTest, TestBadClass) {
    std::shared_ptr<Game> game = std::make_shared<Game>();
    std::shared_ptr<UMLData> data = std::make_shared<UMLData>(game.get());
    data->LoadData(L"data/uml.xml");

    std::shared_ptr<Emitter> emitter = std::make_shared<Emitter>(game.get(), data);

    const unsigned int RandomSeed = 1238197374;
    emitter->GetRandomGood().seed(RandomSeed);

    emitter->SetBadThreshold(0);
    emitter->SetInheritanceThreshold(0);

    // Bad Class Should Be Created
    game->Update(2.6);

    ASSERT_TRUE(game->GetSize() == 4);
}

TEST(EmitterTest, TestGoodInheritance) {
    std::shared_ptr<Game> game = std::make_shared<Game>();
    std::shared_ptr<UMLData> data = std::make_shared<UMLData>(game.get());
    data->LoadData(L"data/uml.xml");

    std::shared_ptr<Emitter> emitter = std::make_shared<Emitter>(game.get(), data);

    const unsigned int RandomSeed = 1238197374;
    emitter->GetRandomGood().seed(RandomSeed);

    emitter->SetBadThreshold(0);
    emitter->SetInheritanceThreshold(100);

    // Good Inheritance Should Be Created
    game->Update(2.6);

    ASSERT_TRUE(game->GetSize() == 4);
}

TEST(EmitterTest, TestBadInheritance) {
    std::shared_ptr<Game> game = std::make_shared<Game>();
    std::shared_ptr<UMLData> data = std::make_shared<UMLData>(game.get());
    data->LoadData(L"data/uml.xml");

    std::shared_ptr<Emitter> emitter = std::make_shared<Emitter>(game.get(), data);

    const unsigned int RandomSeed = 1238197374;
    emitter->GetRandomGood().seed(RandomSeed);

    emitter->SetBadThreshold(0);
    emitter->SetInheritanceThreshold(100);

    // Bad Inheritance Should Be Created
    game->Update(2.6);

    ASSERT_TRUE(game->GetSize() == 4);
}
 
