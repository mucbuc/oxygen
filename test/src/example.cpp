#include <oxygen/src/oxygen.hpp>
#include <oxygen/src/html.hpp>

template <typename T>
static void test_basic_usage(const T& elements_factory)
{
    const auto submit = elements_factory.factory("button").make({ { "content", "hello" } });

    const auto radio = elements_factory.factory("radio_button").make({ { "label", "radio" }, { "id", "test" } });

    const auto fieldset1 = elements_factory.factory("fieldset").make({
        { "label", "llll" },
        { "content", radio + submit },
    });

    const auto fieldset2 = elements_factory.factory("fieldset").make({
        { "label", "llll" },
        { "content", radio + submit },
    });

    std::cout << elements_factory.factory("form").make({ { "content", fieldset1 + fieldset2 },
        { "id", "test" } })
              << std::endl;
}

int main()
{
    test_basic_usage(oxygen::html_factory());

    return 0;
}
