"""Pseudo-builders for building and registering unit tests.
"""

def exists(env):
    return True

def build_integration_test(env, target, source, **kwargs):
    result = env.Program(target, source, **kwargs)
    buildAlias = env.Alias('build-' + target, result)
    env.Alias('build-integration', buildAlias)
    env['ENV']['GTEST_FILTER'] = env.get("gtest_filter", "*")
    env['ENV']['GTEST_BREAK_ON_FAILURE'] = 1;
    runAlias = env.Alias('run-' + target, [result],
        "%s localhost:8889" % result[0].abspath)
    env.AlwaysBuild(runAlias)
    testAliases = ['integration']
    env.Alias(testAliases, runAlias)
    env.AlwaysBuild(testAliases)

    return result

def generate(env):
    env.AddMethod(build_integration_test, 'IntegrationTest')