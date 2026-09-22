let val;
var createCounter = function(init) {
    val=init;
    return {
        
        increment: function() {                        
            return ++val;
        },

        reset: function() {
            val=init;
            return init;
        },

        decrement: function() {
            return --val;
        }
    }
};