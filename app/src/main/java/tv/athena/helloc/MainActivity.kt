package tv.athena.helloc

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import com.salton123.easemob.Facade
import tv.athena.helloc.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding
    val facade = Facade()
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
//        binding.sampleText.text = facade.version()
        binding.sampleText.setOnClickListener {
            facade.createAccount("123456", "111111")
        }
    }

    /**
     * A native method that is implemented by the 'helloc' native library,
     * which is packaged with this application.
     */
//    external fun stringFromJNI(): String

    companion object {
        // Used to load the 'helloc' library on application startup.
        init {
            System.loadLibrary("easemob-facade")
        }
    }
}