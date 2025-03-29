#include <oxygen/src/oxygen.hpp>

static struct ElementFactoriesInstance {
    ElementFactoriesInstance()
    {
        auto button_factory = oxygen::TextFactory(R"(
			<button type="{{type}}">{{content}}</button>
        )")
                                  .set_var("type", "submit");

        m_elements_factory.insert("button", button_factory);

        auto radio_button_factory = oxygen::TextFactory(R"(
			<div>
			    <input type="{{type}}" id="{{id}}" name="{{name}}" value="{{value}}" {{checked}}/>
			    <label for="{{id}}">{{label}}</label>
			</div>
        )")
                                        .set_vars({
                                            { "checked", "" },
                                            { "type", "radio" },
                                        });
        m_elements_factory.insert("radio_button", radio_button_factory);

        auto form_factory = oxygen::TextFactory(R"(
			<form action="{{action}}">
			{{content}}
			{{submit}}
			</form>
        )")
                                .set_var("submit", "");
        m_elements_factory.insert("form", form_factory);
    }

    oxygen::ElementFactories m_elements_factory;

} gElementFactoriesInstance;

oxygen::ElementFactories& elements_factory_instance()
{
    return gElementFactoriesInstance.m_elements_factory;
}

template <typename T>
static void test_basic_usage(const T& elements_factory)
{
    const auto submit = elements_factory.factory("button").make({ { "content", "hello" } });

    const auto radio = elements_factory.factory("radio_button").make({ { "label", "radio" }, { "id", "test" } });

    std::cout << elements_factory.factory("form").make({ { "content", radio + submit },
        { "id", "test" } })
              << std::endl;
}

int main()
{
    test_basic_usage(elements_factory_instance());

    return 0;
}