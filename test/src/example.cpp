#include <oxygen/src/html.hpp>
#include <oxygen/src/oxygen.hpp>

#include <asserter/src/test.hpp>

template <typename T>
static void test_recursion(const T& elements_factory)
{
    const auto fieldset2 = elements_factory.factory("fieldset").make();
    const auto form = elements_factory.factory("form").make({ { "content", fieldset2 } });

    std::cout << form << std::endl;
    FOOTER;
}

template <typename T>
static void test_missing_var(const T& elements_factory)
{
    const auto fieldset2 = elements_factory.factory("fieldset").make({
        { "label", "llll" },
    });

    std::cout << fieldset2 << std::endl;
}

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
    test_recursion(oxygen::html_factory());
    test_missing_var(oxygen::html_factory());
    test_basic_usage(oxygen::html_factory());

    return 0;
}
