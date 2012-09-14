using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace _556.P1
{
    [TestClass]
    public class P1Tests
    {
        private ChocolateBar _bar;

        [TestInitialize]
        public void TestInitialize()
        {
            _bar = new ChocolateBar();
        }

        [TestMethod]
        public void Test0()
        {
            var letters = "srm";
            Assert.AreEqual(3, _bar.maxLength(letters));
        }

        [TestMethod]
        public void Test1()
        {
            var letters = "dengklek";
            Assert.AreEqual(6, _bar.maxLength(letters));
        }


        [TestMethod]
        public void Test2()
        {
            var letters = "haha";
            Assert.AreEqual(2, _bar.maxLength(letters));
        }

        [TestMethod]
        public void Test3()
        {
            var letters = "www";
            Assert.AreEqual(1, _bar.maxLength(letters));
        }

        [TestMethod]
        public void Test4()
        {
            var letters = "thisisansrmbeforetopcoderopenfinals";
            Assert.AreEqual(9, _bar.maxLength(letters));
        }
        
    }
}
