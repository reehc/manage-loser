module QueueX
  extend FFI::Library
  ffi_lib './libqueue.so'
  attach_function :show, [], :void
  attach_function :init, [], :void
  attach_function :freeQ, [], :void
  attach_function :ih, [:int], :void
  attach_function :it, [:int], :void
  attach_function :rh, [], :void
  attach_function :reverse, [], :void
end
