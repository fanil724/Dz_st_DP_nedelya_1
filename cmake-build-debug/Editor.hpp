#pragma once

#include <iostream>
#include <functional>
#include <vector>

class Features {
public:
    virtual ~Features() = default;

    virtual void render() = 0;
};

class Features_Editor : public Features {
public:
    Features_Editor(std::function<void()> onclick)
            : onclick_(std::move(onclick)) {}

    virtual void click() {
        onclick_();
    }

protected:
    std::function<void()> onclick_;

};

class Creation : public Features_Editor {
public:
    Creation(
            std::function<void()> onclick,
            std::string name)
            : Features_Editor(std::move(onclick)),
              name_(std::move(name)) {}

    void render() override {
        std::cout << "<Features_Editor>"
                  << name_
                  << "</Features_Editor>";
    }

private:
    std::string name_;
};


class Opening : public Features_Editor {
public:
    Opening(
            std::function<void()> onclick,
            std::string name)
            : Features_Editor(std::move(onclick)),
              name_(std::move(name)) {}

    void render() override {
        std::cout << "<Features_Editor>"
                  << name_
                  << "</Features_Editor>";
    }

private:
    std::string name_;
};

class Save : public Features_Editor {
public:
    Save(
            std::function<void()> onclick,
            std::string name)
            : Features_Editor(std::move(onclick)),
              name_(std::move(name)) {}

    void render() override {
        std::cout << "<Features_Editor>"
                  << name_
                  << "</Features_Editor>";
    }

private:
    std::string name_;
};

class SaveNewFail : public Features_Editor {
public:
    SaveNewFail(
            std::function<void()> onclick,
            std::string name)
            : Features_Editor(std::move(onclick)),
              name_(std::move(name)) {}

    void render() override {
        std::cout << "<Features_Editor>"
                  << name_
                  << "</Features_Editor>";
    }

private:
    std::string name_;
};

class Seal : public Features_Editor {
public:
    Seal(
            std::function<void()> onclick,
            std::string name)
            : Features_Editor(std::move(onclick)),
              name_(std::move(name)) {}

    void render() override {
        std::cout << "<Features_Editor>"
                  << name_
                  << "</Features_Editor>";
    }

private:
    std::string name_;
};

class Close : public Features_Editor {
public:
    Close(
            std::function<void()> onclick,
            std::string name)
            : Features_Editor(std::move(onclick)),
              name_(std::move(name)) {}

    void render() override {
        std::cout << "<Features_Editor>"
                  << name_
                  << "</Features_Editor>";
    }

private:
    std::string name_;
};

class Editor {
public:
    std::vector<Features &&> features_;

    void add_features(Features &&features) {
        features_.push_back(std::move(features));
    }
};

class EditorBuilder {
public:
    virtual ~EditorBuilder() = default;

    virtual void add_features_editor(std::function<void()> onclick, std::string name) = 0;

    virtual Editor &get_object() = 0;

private:
    Editor object_;
};

class Window {
public:
    Window(EditorBuilder &&builder)
            : builder_(std::move(builder)) {}

    void initialize() {
        builder_.add_features_editor([]() {}, "test");
        builder_.add_features_editor([]() {}, "test");

        for (auto &&element: builder_.get_object().features_) {
            element.render();
        }
    }

private:
    EditorBuilder &&builder_;
};

class CreationEditorBuilder : public EditorBuilder {
public:
    void add_features_editor(std::function<void()> onclick, std::string name) override {
        editor.add_features(std::move(Creation(std::move(onclick), std::move(name)));
    }

    Editor &get_object() override {
        return editor;
    }

private:
    Editor editor;
};
class OpeningEditorBuilder : public EditorBuilder {
public:
    void add_features_editor(std::function<void()> onclick, std::string name) override {
        editor.add_features(std::move(Creation(std::move(onclick), std::move(name)));
    }

    Editor &get_object() override {
        return editor;
    }

private:
    Editor editor;
};
class SaveEditorBuilder : public EditorBuilder {
public:
    void add_features_editor(std::function<void()> onclick, std::string name) override {
        editor.add_features(std::move(Creation(std::move(onclick), std::move(name)));
    }

    Editor &get_object() override {
        return editor;
    }

private:
    Editor editor;
};
class SaveNewFailEditorBuilder : public EditorBuilder {
public:
    void add_features_editor(std::function<void()> onclick, std::string name) override {
        editor.add_features(std::move(Creation(std::move(onclick), std::move(name)));
    }

    Editor &get_object() override {
        return editor;
    }

private:
    Editor editor;
};
class SealEditorBuilder : public EditorBuilder {
public:
    void add_features_editor(std::function<void()> onclick, std::string name) override {
        editor.add_features(std::move(Creation(std::move(onclick), std::move(name)));
    }

    Editor &get_object() override {
        return editor;
    }

private:
    Editor editor;
};
class CloseEditorBuilder : public EditorBuilder {
public:
    void add_features_editor(std::function<void()> onclick, std::string name) override {
        editor.add_features(std::move(Creation(std::move(onclick), std::move(name)));
    }

    Editor &get_object() override {
        return editor;
    }

private:
    Editor editor;
};