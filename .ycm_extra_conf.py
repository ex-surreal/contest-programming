import os

ext_to_lang = {
    '.c': 'c',
    '.cc': 'c++',
    '.c++': 'c++',
    '.cpp': 'c++',
    '.h': 'c++',
    '.hpp': 'c++'
}

def Settings( **kwargs ):
    _, ext = os.path.splitext(kwargs['filename'])
    if not ext_to_lang.has_key(ext):
        return {}
    return {
        'flags': [ '-x', ext_to_lang[ext], '-Wall', '-Wextra', '-Werror', '-I', './include' ],
    }
