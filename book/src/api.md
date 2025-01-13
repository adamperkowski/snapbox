# API Reference
List of modules available in snapbox:
- [snapbox](#snapbox)
- [snapbox/header](#snapboxheader)
- [snapbox/status](#snapboxstatus)

## snapbox
The main module. It is a wrapper for the C++ `curl.h` functionality.

<div id="snapbox-fn-get">
<code class="language-jule hljs"><span class="hljs-keyword">fn</span> <span class="hljs-function">GET</span>(url<span class="hljs-punctuation">:</span> <span class="hljs-operator">&amp;</span><span class="hljs-type">str</span>)<span class="hljs-punctuation">:</span> <a href="#snapbox-struct-getrequest">getRequest</a>
</code>
</div>

---

<div id="snapbox-struct-getrequest">
<code class="language-jule hljs"><span class="hljs-keyword">struct</span> getRequest {
    url<span class="hljs-punctuation">:</span>         <span class="hljs-type">str</span>,
    <span class="hljs-storage">mut</span> headers<span class="hljs-punctuation">:</span> <a href="#snapboxheader">header</a><span class="hljs-punctuation">:</span><span class="hljs-punctuation">:</span><a href="#snapboxheader-type-headermap">HeaderMap</a>
}
</code>
</div>

<div id="snapbox-struct-getrequest-fn-send">
<code class="language-jule hljs"><span class="hljs-keyword">fn</span> <span class="hljs-function">Send</span>(<span class="hljs-storage">self</span>)<span class="hljs-punctuation">:</span> <span class="hljs-keyword">cpp</span><span class="hljs-punctuation">.</span><a href="#snapbox-cpp-struct-getresponse">getResponse</a>
</code>
</div>

<div id="snapbox-struct-getrequest-fn-headers">
<code class="language-jule hljs"><span class="hljs-keyword">fn</span> <span class="hljs-function">Headers</span>(<span class="hljs-storage">self</span><span class="hljs-punctuation">,</span> headers<span class="hljs-punctuation">:</span> <a href="#snapboxheader">header</a><span class="hljs-punctuation">:</span><span class="hljs-punctuation">:</span><a href="#snapboxheader-type-headermap">HeaderMap</a>)<span class="hljs-punctuation">:</span> <a href="#snapbox-struct-getrequest">getRequest</a>
</code>
</div>

---

<div id="snapbox-cpp-struct-getresponse">
<code class="language-jule hljs"><span class="hljs-keyword">cpp</span> <span class="hljs-keyword">struct</span> getResponse {
    url<span class="hljs-punctuation">:</span>    <span class="hljs-type">str</span>,
    status<span class="hljs-punctuation">:</span> <a href="#snapboxstatus">status</a><span class="hljs-punctuation">:</span><span class="hljs-punctuation">:</span><a href="#snapboxstatus-type-statuscode">StatusCode</a>
}
</code>
</div>

## snapbox/header
This module includes a collection of [HTTP headers constants] and types.

<div id="snapboxheader-type-headermap">
<code class="language-jule hljs"><span class="hljs-keyword">type</span> HeaderMap<span class="hljs-punctuation">:</span> <span class="hljs-keyword">map</span>[<span class="hljs-type">str</span>]<span class="hljs-type">str</span>
</code>
</div>

<div id="snapboxheader-fn-slice">
<code class="language-jule hljs"><span class="hljs-keyword">fn</span> <span class="hljs-function">Slice</span>(headers<span class="hljs-punctuation">:</span> <a href="#snapboxheader-type-headermap">HeaderMap</a>)<span class="hljs-punctuation">:</span> []<span class="hljs-type">str</span>
</code>
</div>

## snapbox/status
This module includes a collection of [HTTP status code constants], types and classifying functions.

<div id="snapboxstatus-type-statuscode">
<code class="language-jule hljs"><span class="hljs-keyword">type</span> StatusCode<span class="hljs-punctuation">:</span> <span class="hljs-type">int</span>
</code>
</div>

<div id="snapboxstatus-fn-isinformational">
<code class="language-jule hljs"><span class="hljs-keyword">fn</span> <span class="hljs-function">IsInformational</span>(code<span class="hljs-punctuation">:</span> <a href="#snapboxstatus-type-statuscode">StatusCode</a>)<span class="hljs-punctuation">:</span> <span class="hljs-type">bool</span>
</code>
</div>

<div id="snapboxstatus-fn-issuccess">
<code class="language-jule hljs"><span class="hljs-keyword">fn</span> <span class="hljs-function">IsSuccess</span>(code<span class="hljs-punctuation">:</span> <a href="#snapboxstatus-type-statuscode">StatusCode</a>)<span class="hljs-punctuation">:</span> <span class="hljs-type">bool</span>
</code>
</div>

<div id="snapboxstatus-fn-isredirection">
<code class="language-jule hljs"><span class="hljs-keyword">fn</span> <span class="hljs-function">IsRedirection</span>(code<span class="hljs-punctuation">:</span> <a href="#snapboxstatus-type-statuscode">StatusCode</a>)<span class="hljs-punctuation">:</span> <span class="hljs-type">bool</span>
</code>
</div>

<div id="snapboxstatus-fn-isclienterror">
<code class="language-jule hljs"><span class="hljs-keyword">fn</span> <span class="hljs-function">IsClientError</span>(code<span class="hljs-punctuation">:</span> <a href="#snapboxstatus-type-statuscode">StatusCode</a>)<span class="hljs-punctuation">:</span> <span class="hljs-type">bool</span>
</code>
</div>

<div id="snapboxstatus-fn-isservererror">
<code class="language-jule hljs"><span class="hljs-keyword">fn</span> <span class="hljs-function">IsServerError</span>(code<span class="hljs-punctuation">:</span> <a href="#snapboxstatus-type-statuscode">StatusCode</a>)<span class="hljs-punctuation">:</span> <span class="hljs-type">bool</span>
</code>
</div>

[HTTP headers constants]: https://github.com/adamperkowski/snapbox/blob/main/snapbox/header/names.jule
[HTTP status code constants]: https://github.com/adamperkowski/snapbox/blob/main/snapbox/status/codes.jule
