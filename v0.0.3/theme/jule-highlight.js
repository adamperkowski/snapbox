// Jule syntax highlighting for highlight.js
// Don't use this, it's bad

hljs.registerLanguage('jule', (hljs) => ({
    name: 'Jule',
    aliases: ['jule'],
    keywords: {
      keyword:
        'chan map error use fn struct byte rune enum unsafe let match defer if else for in impl trait break continue goto cpp type ret fall co let select',
      type:
        'int uint uintptr i8 i16 i32 i64 u8 u16 u32 u64 f32 f64 bool str any byte rune',
      constant:
        'static const mut self',
      literal:
        'true false nil',
    },
    contains: [
      {
        className: 'meta',
        begin: '#\\p\\+\\>',
        relevance: 10
      },
      {
        className: 'function',
        begin: '\\b\\w+\\s*(?=\\()'
      },
      {
        className: 'number',
        variants: [
          { begin: '\\b\\d+(_\\d+)*\\b' },
          { begin: '\\b\\d+(_\\d+)*(\\.\\d+(_\\d+)*([eE][-+]?\\d+)?)?\\b' },
          { begin: '\\b0b[01]+(_[01]+)*\\b' },
          { begin: '\\b0o[0-7]+(_[0-7]+)*\\b' },
          { begin: '\\b0x[0-9a-fA-F]+(_[0-9a-fA-F]+)*\\b' }
        ],
        relevance: 0
      },
      {
        className: 'string',
        variants: [
          { begin: '\'', end: '\'', contains: [hljs.BACKSLASH_ESCAPE] },
          { begin: '"', end: '"', contains: [hljs.BACKSLASH_ESCAPE] },
          { begin: '`', end: '`' },
          { begin: '"""', end: '"""' }
        ]
      },
      hljs.COMMENT("//", "$"),
      hljs.COMMENT("/\\*", "\\*/"),
      {
        className: 'operator',
        begin: /[+\-*\/%|&^!]=?|[<>]=?|[<>]{2}=?|&&|\|\|/
      },
      {
        className: 'punctuation',
        begin: /[.,;:]/
      }
    ]
}));

hljs.initHighlightingOnLoad();
