using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace _556.P3
{
    [TestClass]
    public class P3Tests
    {
        private LeftRightDigitsGame _game;

        [TestInitialize]
        public void TestInitialize()
        {
            _game = new LeftRightDigitsGame();
        }

        [TestMethod]
        public void Test0()
        {
            string data = "565";

            Assert.AreEqual("556", _game.minNumber(data));
        }

        [TestMethod]
        public void Test1()
        {
            string data = "9876543210";

            Assert.AreEqual("1234567890", _game.minNumber(data));
        }

        [TestMethod]
        public void Test2()
        {
            string data = "8016352";

            Assert.AreEqual("1086352", _game.minNumber(data));
        }
    }
}
