#pragma once

#include <array>
#include <map>
#include <memory>
#include <string>

#include <asserter/src/asserter.hpp>

namespace oxygen {

struct TextFactory {
    TextFactory(std::string);

    template <typename T>
    TextFactory& set_var(std::string name, const T& value)
    {
        set_var(name, std::to_string(value));
        return *this;
    }
    TextFactory& set_var(std::string name, std::string value);
    TextFactory& set_var(std::string name, const char* value);
    TextFactory& set_vars(std::map<std::string, std::string>);

    std::string make(std::map<std::string, std::string> = {}) const;

private:
    TextFactory() = delete;

    const std::string m_template;
    std::map<std::string, std::string> m_variables;
};

struct ElementFactories {
    ElementFactories& insert(std::string name, const TextFactory&);
    const TextFactory& factory(std::string name) const;

private:
    std::map<std::string, TextFactory> m_factories;
};

struct Menu {
    Menu(const ElementFactories& factory);

    const TextFactory& factory(std::string name) const;

private:
    const ElementFactories& m_element_factory;
};

}
